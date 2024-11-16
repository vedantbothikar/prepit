/*
Brute force:
- Double for loop for choosing all substrings, and then on each substring check if it is palindrome or not

for(i = 0 to n-1){
    for(j = i to n-1) {

        checkIfPalindrome(s.substr(i to j));
    }
}
checkIfPalindrome() // this can be done in O(N) (2 pointer technique, from start ptr and end ptr)

So, overall TC: O(N^3)
SC: O(1)

BETTER APPROACH:
Strategy:
Here we are kind of going to bring down the time by doing the check of palindrome in O(1)

s = "babad" 

- Consider every element as the center of the palindrome 
    - Now expand left and right 
        - For example if you have a, then you can go bab
        - Now checking this as palindrome will only mean you need to check the left and right characters that you have exapanded. This is O(1)
        - if it is palindrome, then expand further,
        - else stop and go to next element and repeat procedure


Above will solve it in O(N^2)
But this will solve it for all substrings which are of odd lengths only.
This is because we are first considering an element and then expanding left and right. So there will always be odd number of elements in the string.

To solve for even number of elements:
Consider the element and its next element at the same time, 
    - check if they are equal to each other, 
        - if yes, then continue expanding left and right
        - else, go to next element and repeat procedure

When expanding we need to take care of index out of bounds scenarios


*/
class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        // base condition: n == 1
        if(n == 1) return s;

        int maxLen = INT_MIN; 
        int ansLeftPtr = 0;
        int ansRightPtr = 0;

        // CASE 1: solving for ODD palindromic strings
        for(int i = 0; i < n; i++) {
            
            int left = i-1;
            int right = i+1;
            while(left >= 0 and right <= n-1) {

                if(s[left] != s[right]) break; 

                if(right - left + 1 > maxLen) {
                    ansLeftPtr = left;
                    ansRightPtr = right;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }
        }

        // CASE 2: solving for EVEN palindromic strings
        for(int i = 0; i < n; i++) {
            
            // consider two elements now
            int next = i+1;
            if(next > n-1 or (s[i] != s[next])) continue;

            // If current and next elements are equal, we got a potential ans
            if(next - i + 1 > maxLen) {
                ansLeftPtr = i;
                ansRightPtr = next;  
                maxLen = next - i + 1;
            }         

            // Now that the considered 2 elements are equal: expand window now
            int left = i-1;
            int right = next+1;    
            while(left >= 0 and right <= n-1) {

                if(s[left] != s[right]) break;
                 
                if(right - left + 1 > maxLen) { 
                    ansLeftPtr = left;
                    ansRightPtr = right;
                    maxLen = right - left + 1;
                }

                left--;
                right++;
            }
        }
        
        return s.substr(ansLeftPtr, maxLen);
    }
};