/*

- https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=programming-skills

start traversing until you reach end of either of the words
keep a single pointer index
first append the char at index of word1 then append the char at index of word2
and keep doing this

when the loop ends, you either have chars in word1 or word2
so append chars of the string that is pending


*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        int index = 0;

        // add chars alternately
        string ans = "";
        while(index < n && index < m) {
            
            cout << "ans: " << word1[index] << endl;
            char ch1 = word1[index];
            char ch2 = word2[index];
            ans += word1[index];
            ans += word2[index];

            // NOTE: Below wont work because that what it would do is add the characters of word1 and word2 together and then add the result to ans 
            // ans += word1[index] + word2[index];
            index++;
        }

        // add chars of word1 if pending
        while(index < n) {
            ans += word1[index];
            index++;
        }

        // add chars of word2 if pending
        while(index < m) {
            ans += word2[index];
            index++;
        }

        return ans;
    }
};