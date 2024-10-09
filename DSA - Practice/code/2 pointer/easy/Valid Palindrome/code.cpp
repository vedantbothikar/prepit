/*

    alnum(character) => tells us if the character is alnum or not

2 pointers
start, end

while start <= end
if arr[start] and arr[end] is alnum:
    - if start and end are NOT equal
        return false
    else
        start++
        end--
else arr[start] is NOT alnum:
    start++
    continue;
else 
    end--
    continue;

*/



class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.length();
        int start = 0;
        int end = n-1;

        while(start <= end) {

            if(isalnum(s[start]) and isalnum(s[end])) {

                if(tolower(s[start]) != tolower(s[end])) return false;
                
                start++;
                end--;
            }
            else if(!isalnum(s[start])) {
                start++;
            }
            else if(!isalnum(s[end])) {
                end--;
            }
        }

        return true;        
    }
};