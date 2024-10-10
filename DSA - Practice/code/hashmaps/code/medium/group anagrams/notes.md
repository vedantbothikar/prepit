### **Explanation of the Code:**

The goal of the code is to **group anagrams** together from a given list of strings. An **anagram** is a word or phrase formed by rearranging the letters of another word, like `listen` and `silent`. The idea behind the code is that if two words are anagrams, they will have the same characters when sorted. This insight is leveraged to group the anagrams together.

#### **Key Steps and Logic**:

1. **Data Structure**:
   - The core data structure used here is an **unordered_map** (`mp`), where the **key** is a **sorted version** of each string, and the **value** is a vector of integers (indices) that store the positions of the original strings in the `strs` array.
   - Sorting each word ensures that all anagrams will have the same sorted key.

2. **Step-by-step explanation**:

### Code Breakdown:

```cpp
unordered_map<string, vector<int>> mp;
```
- **`mp`**: This is an unordered map where the **key** is a **sorted version of a string** and the **value** is a vector of integers, which holds the indices of the original strings that are anagrams of each other.

#### **First Loop: Populating the Hashmap**

```cpp
for(int i = 0; i < strs.size(); i++) {
    string str = strs[i];
    string sortedStr = str;  // Make a copy of the original string
    sort(sortedStr.begin(), sortedStr.end());  // Sort the copied string
    mp[sortedStr].push_back(i);  // Add the index of the original string to the map
}
```

- **Looping over each word**:
  - `str = strs[i];`: For each word in the input vector `strs`, we make a copy of the string.
  - `sort(sortedStr.begin(), sortedStr.end());`: The copied string is then **sorted**. Sorting ensures that all anagrams will end up with the same sorted string (as the key).
  - `mp[sortedStr].push_back(i);`: The index of the original word (`i`) is added to the vector associated with this sorted string in the hashmap. This allows us to later retrieve the original words using their indices.

#### **Second Loop: Creating the Output Vector**

```cpp
vector<vector<string>> ans;
for (auto& [key, value] : mp) {
    vector<string> currentAns;
    for (int i : value) {
        currentAns.push_back(strs[i]);  // Use the indices to retrieve the original strings
    }
    ans.push_back(currentAns);  // Add the group of anagrams to the final result
}
```

- **Iterating over the map**:
  - For each **key** (sorted string) in the map, we retrieve the vector of indices (`value`), which tells us which words in the original array `strs` are anagrams.
  
- **Building the result**:
  - For each group of indices stored in the map, a new vector (`currentAns`) is created.
  - Using the indices stored in the map, the corresponding original strings are fetched from `strs` and added to the `currentAns` vector.
  - After processing each group of anagrams, the `currentAns` vector is pushed into the final result vector `ans`.

#### **Return Result**:
```cpp
return ans;
```
- After processing all entries in the map, the result vector `ans`, which contains groups of anagrams, is returned.

---

### **Example Walkthrough**:

Suppose we have the input `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]`.

1. **First Loop**:
   - For "eat", the sorted string is "aet", so the map becomes: `{"aet": [0]}`
   - For "tea", the sorted string is also "aet", so the map becomes: `{"aet": [0, 1]}`
   - For "tan", the sorted string is "ant", so the map becomes: `{"aet": [0, 1], "ant": [2]}`
   - For "ate", the sorted string is "aet", so the map becomes: `{"aet": [0, 1, 3], "ant": [2]}`
   - For "nat", the sorted string is "ant", so the map becomes: `{"aet": [0, 1, 3], "ant": [2, 4]}`
   - For "bat", the sorted string is "abt", so the map becomes: `{"aet": [0, 1, 3], "ant": [2, 4], "abt": [5]}`

2. **Second Loop**:
   - For the key "aet", we look at indices `[0, 1, 3]` in `strs`, corresponding to "eat", "tea", and "ate". These are grouped together.
   - For the key "ant", we look at indices `[2, 4]`, corresponding to "tan" and "nat".
   - For the key "abt", we look at index `[5]`, corresponding to "bat".

3. **Final Output**:
   The final result will be:
   ```
   [
     ["eat", "tea", "ate"],
     ["tan", "nat"],
     ["bat"]
   ]
   ```

---

### **Time Complexity**:

1. **Sorting** each string takes **O(k log k)**, where `k` is the average length of a string.
2. Since there are `n` strings, the total time complexity for the first loop (sorting and populating the map) is **O(n * k log k)**.
3. The second loop, where we iterate over the map and build the result, takes **O(n * k)**, since we're accessing each string exactly once and copying it into the result.

Thus, the overall time complexity is **O(n * k log k)**.

### **Space Complexity**:
- The space complexity is **O(n * k)** to store the hashmap (keys are sorted strings, values are vectors of indices) and the result vector of vectors. Additionally, sorting each string takes **O(k)** extra space (though this may be done in-place).

### **Summary**:
This solution groups anagrams by leveraging the fact that all anagrams share the same sorted sequence of characters. The hashmap stores the sorted strings as keys and their corresponding original string indices as values. This allows efficient grouping of anagrams with a time complexity of **O(n * k log k)**.