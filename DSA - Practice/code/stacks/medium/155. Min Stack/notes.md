# MinStack — Two Approaches and Complexity

This document explains two standard implementations of the **MinStack** problem (LeetCode):

* **Approach 1:** Two stacks (main stack + min-tracker stack that stores every new minimum).
* **Approach 2:** Two stacks where the min-tracker stores **(value, count)** pairs to avoid repetition.

Both approaches support the usual operations: `push(x)`, `pop()`, `top()`, and `getMin()`. The goal is to have `getMin()` operate in **O(1)** time.

---

## Approach 1 — Two stacks (push minimums to minStack)

### Idea

Maintain two stacks:

* `stack` — the main stack storing all pushed values.
* `minStack` — stores the current minimum(s). Whenever we push a value `x` that is **less than or equal to** the current minimum (or `minStack` is empty), we also push `x` onto `minStack`.

This ensures that `minStack.top()` is always the current minimum. When popping, if `stack.top()` equals `minStack.top()` we pop `minStack` as well.

### Code (C++)

```cpp
class MinStack {
private:
    stack<int> stack, minStack;

public:
    MinStack() {}

    void push(int x) {
        stack.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (stack.top() == minStack.top())
            minStack.pop();
        stack.pop();
    }

    int top() { return stack.top(); }

    int getMin() { return minStack.top(); }
};
```

### Correctness intuition

* `minStack` stores a history of minima seen so far, in the order they become the active minimum.
* For each `push(x)` that introduces a new minimum (or equals current minimum), we remember it. On `pop()`, if we remove the value that was providing the minimum, we also remove it from `minStack`, revealing the previous minimum.

### Time & Space Complexity

* **Time (per operation):** `O(1)` for `push`, `pop`, `top`, and `getMin`.
* **Space:** `O(n)` worst-case extra space. In the worst case (strictly decreasing pushes) `minStack` stores every element and so uses O(n) additional space.

### Pros

* Very simple and easy to implement.
* Constant-time operations and straightforward logic.

### Cons

* If the current minimum value is pushed many times (duplicates), `minStack` will store that same minimum repeatedly — unnecessary duplication of storage.
* In scenarios with many repeated minimums, the extra storage can be larger than necessary.

---

## Approach 2 — Two stacks with counts on the min-tracker (value, count)

### Motivation / Why we need Approach 2

Approach 1 avoids a correctness bug by storing the minimum every time a value equal to the current minimum is pushed. But that causes **redundant copies** of the same minimum in `minStack` when the minimum repeats frequently. Approach 2 reduces this redundancy by storing each distinct minimum value once, along with a **count** of how many times it currently appears on the main stack.

This keeps `getMin()` still at `O(1)`, but reduces `minStack` size when many duplicate minima are pushed.

### Idea

* `stack` — main stack storing all values (unchanged).
* `minStack` — stack of pairs `(value, count)` where `value` is a minimum value and `count` is how many times that value appears among elements currently in `stack` that are less than or equal to all elements above them.

On `push(x)`:

* Always push `x` to `stack`.
* If `minStack` is empty or `x < minStack.top().first`, push `(x, 1)` to `minStack`.
* Else if `x == minStack.top().first`, increment `minStack.top().second`.

On `pop()`:

* If `stack.top() == minStack.top().first`, decrement `minStack.top().second`.
* If that count becomes `0`, pop the top pair from `minStack`.
* Pop from the main `stack`.

### Code (C++)

```cpp
class MinStack {
private:
    std::stack<int> stack;
    std::stack<std::pair<int, int>> minStack;

public:
    MinStack() {}

    void push(int x) {
        stack.push(x);
        if (minStack.empty() || x < minStack.top().first) {
            minStack.push({x, 1});
        } else if (x == minStack.top().first) {
            minStack.top().second++;
        }
    }

    void pop() {
        if (stack.top() == minStack.top().first) {
            minStack.top().second--;
            if (minStack.top().second == 0)
                minStack.pop();
        }
        stack.pop();
    }

    int top() { return stack.top(); }
    int getMin() { return minStack.top().first; }
};
```

### Correctness intuition

* `minStack` now stores each minimum value once, with a count that tracks how many occurrences of that minimum exist in `stack` (and are still active). When we remove one occurrence via `pop()`, we decrement the counter; only when the counter hits zero do we discard that minimum and expose the previous minimum.

### Time & Space Complexity

* **Time (per operation):** `O(1)` for `push`, `pop`, `top`, and `getMin`.
* **Space:** `O(n)` worst-case, but in practice better than Approach 1 when there are many repeated minima. `minStack` holds at most one entry per *distinct* minimum value (with counts), rather than one entry per push that was a minimum.

### Pros

* Saves space when the current minimum repeats many times.
* Still `O(1)` for all operations.

### Cons

* Slightly more bookkeeping (store counts and update them).
* In the worst case (strictly decreasing sequence), it still needs O(n) space — same as Approach 1.

---

## Example walkthrough (simple)

Sequence pushed: `2, 2, 1, 1, 1, 3, pop(), pop()`

* **Approach 1** `minStack` evolution: `[]` → `[2]` → `[2,2]` → `[2,2,1]` → `[2,2,1,1]` → `[2,2,1,1,1]` → (push 3: unchanged) → (pop 3: unchanged) → (pop 1: pop minStack) ...

  * lots of repeated `1`s stored separately.

* **Approach 2** `minStack` evolution: `[]` → `[(2,1)]` → `[(2,2)]` → `[(2,2),(1,1)]` → `[(2,2),(1,2)]` → `[(2,2),(1,3)]` → (push 3: unchanged) → (pop 3: unchanged) → (pop 1: `[(2,2),(1,2)]`) ...

  * counts compactly represent duplicates.

---

## Which approach to choose?

* If code simplicity and minimal bookkeeping are priorities and input sizes or duplicates are not a concern, **Approach 1** is fine and easy to implement.
* If you expect many repeated pushes of the same minimum value (duplicates), and you want to reduce memory overhead, use **Approach 2** (value + count pairs) — it reduces redundant storage while keeping all operations `O(1)`.

Both are widely accepted; Approach 2 is a small and practical improvement over Approach 1 when memory overhead from duplicates matters.

---

## Summary (quick)

* Both approaches: `O(1)` per operation.
* Space: `O(n)` worst-case; Approach 2 often uses less space by compressing consecutive identical minima.
* Approach 2 fixes the *storage* inefficiency (not a correctness problem) present in Approach 1 when many duplicates of the current minimum are pushed.

---

### References / Further reading

* LeetCode problem: *Min Stack* (search LeetCode for problem number and examples).
* Common interview notes: using auxiliary stack(s) to maintain additional information like the current minimum.

*End of document.*
