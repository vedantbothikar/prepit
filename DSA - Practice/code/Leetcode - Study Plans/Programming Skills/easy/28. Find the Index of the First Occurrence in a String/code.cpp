/*
- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=programming-skills


normal iteration
whenever the first character of needle matches the haystack, then call a function to check if the needle exists in the haystack starting from the currentIndex

if present, return true
else return false
    and keep checking ahead

Worst case: O(n * m)

*/
class Solution {

    bool needlePresent(string haystack, string needle, int hIndex) {

        int n = haystack.size();
        int m = needle.size();

        int nIndex = 0;
        while(hIndex < n && nIndex < m) {

            if(haystack[hIndex] != needle[nIndex]) return false;

            hIndex++;
            nIndex++;
        }

        if(nIndex != needle.size()) return false;

        return true;
    }

public:
    int strStr(string haystack, string needle) {


        for(int i = 0; i < haystack.size(); i++) {

            if(haystack[i] == needle[0]) {

                if(needlePresent(haystack, needle, i)) return i;
            }
        }

        return -1;
    }
};