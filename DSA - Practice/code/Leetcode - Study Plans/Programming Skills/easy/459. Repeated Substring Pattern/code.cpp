/*

- https://leetcode.com/problems/repeated-substring-pattern/?envType=study-plan-v2&envId=programming-skills

- Problem:
    Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

- Intuition:
    - if we can find a substring that is repeating and we can append that substring x times to get the string s then we can say that the string s is a repeated substring pattern

- Approach:
    - we need to find a substring that is repeating and we can append that substring x times to get the string s
    - so we need to find the substring that is repeating and the length of the substring must be a divisor of the length of the string s
    - so we will iterate over all the possibilities of the substring and check if the substring is repeating and we can append that substring x times to get the string s


we find the possibility of a substring that is repeating and append that substring x times to check if the new string matches that to the given input

so we need to understand that the substring repeating must start from the beginning of the string s
and we need to understand that the length of the ubstring repeating must be a divisor of the length of s (which means sLen % substringLen == 0)

and if we repeat the pattern of substring x times we will get s
but can we find x?
x = sLen / substringLen

so we will check for all possibilities of substrings and create the pattern and match if the pattern equals to the s


TC: O(n * root(n))

*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int sLen = s.size();

        // i is the substringLen
        for(int i = 1; i <= sLen/2; i++){

            if(sLen % i != 0) continue;

            // we got a possibility
            // create the pattern and check if it equals to s
            string pattern = "";

            int x = sLen / i;
            string repeatingSubStr = s.substr(0, i);

            for(int i = 0; i < x; i++) {
                pattern += repeatingSubStr;
            }

            if(s == pattern) return true;
        }

        return false;
    }
};