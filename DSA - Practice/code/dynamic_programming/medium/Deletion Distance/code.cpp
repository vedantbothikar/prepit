/*
Deletion Distance The deletion distance of two strings is the minimum number of characters you need to delete in the two strings in order to get the same string. For instance, the deletion distance between "heat" and "hit" is 3:

By deleting 'e' and 'a' in "heat", and 'i' in "hit", we get the string "ht" in both cases. We cannot get the same string from both strings by deleting 2 letters or fewer. Given the strings str1 and str2, write an efficient function deletionDistance that returns the deletion distance between them. Explain how your function works, and analyze its time and space complexities.

Cases:

empty strings
exactly unequal strings etc

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to calculate deletion distance
    int deletionDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // Create a memoization table initialized with -1
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        // Call the helper function
        return traverse(str1, str2, 0, 0, memo);
    }

private:
    // Recursive helper function with memoization
    int traverse(string& str1, string& str2, int i, int j, vector<vector<int>>& memo) {
        // Base cases
        if (i == str1.size() && j == str2.size()) return 0; // Both strings are empty
        if (i == str1.size()) return str2.size() - j;       // Only str2 is left
        if (j == str2.size()) return str1.size() - i;       // Only str1 is left

        // If already calculated, return the stored value
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, no deletion needed for this character
        if (str1[i] == str2[j]) {
            return memo[i][j] = traverse(str1, str2, i + 1, j + 1, memo);
        } else {
            // If characters don't match, delete one character and take the minimum of two options:
            // 1. Delete from str1 and move to the next character in str1.
            // 2. Delete from str2 and move to the next character in str2.
            int deleteFromStr1 = traverse(str1, str2, i + 1, j, memo);
            int deleteFromStr2 = traverse(str1, str2, i, j + 1, memo);
            return memo[i][j] = min(deleteFromStr1, deleteFromStr2) + 1;
        }
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    string str1 = "sea";
    string str2 = "eat";

    int result = solution.deletionDistance(str1, str2);
    cout << "The deletion distance is: " << result << endl;

    return 0;
}
