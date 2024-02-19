3 ways of solving dp problems

- memoization TC: O(N) SC: 2\*O(N) = O(N)
- tabulation TC: O(N) SC: O(N)
- space optimization TC: O(N) SC: O(1)

So, generally in problems like "find the min/max number of ways of..." or questions where there are multiple ways of choosing or similar to this... we use recursion
and in these cases dp could be used to optimize

recursion is also used to for problems like count the number of ways, or find the best way... etc

### Trick to solving dp problems

1. Represent the problem in terms of index
2. Do all possible stuff on that index as asked in the problem statement - for example: include-exclude, plus-minus
3. aggregate: if we have to find the total number of ways: then add... if you want to find the min then find the min, etc etc
