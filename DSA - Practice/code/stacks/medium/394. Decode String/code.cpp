/*

Problem: Decode String

https://leetcode.com/problems/decode-string/description/?envType=company&envId=bytedance&favoriteSlug=bytedance-six-months
Solution: https://neetcode.io/solutions/decode-string


Keep pushing to the stack until you get a closing bracket.
Once you get a closing bracket:
    - pop until you get the entire encoded_string
    - pop until you get the entire k
    - multiply k * encoded_string
    - IMP: push the multiplied (decoded) string into the stack again
        - This is imp and need to be done since it will handle the nested brackets 
        gracefully.




*/
class Solution {

    bool isThisDigit(string &s) {

        // base case
        if(s == "") return false;

        // check character by character
        // NOTE: in our solution it is always going to have a single char
        // but we need to do this because this is a generic technique to check 
        // if the current string is a digit

        for(char ch : s) {
            if(!isdigit(ch)) return false;
        }

        return true;
    }

public:
    string decodeString(string s) {
        
        int n = s.size();
        stack<string> st;

        for(int i = 0; i < n; i++) {

            char currCh = s[i];

            // append the currCh to stack if not a closing bracket
            if(currCh != ']') {
                // convert currCh to string and append
                string temp;
                temp += currCh;

                st.push(temp);
            }

            else {

                // this means we have a closing bracket
                // get the encoded_string, and k
                // get the decoded_string and push to stack

                // pop until you have a opening bracket to get the encoded_string
                string encoded_string = "";
                while(st.top() != "[") {

                    encoded_string = st.top() + encoded_string;
                    st.pop();
                }

                // pop the opening bracket
                st.pop();

                // pop until you have digits or end of stack
                // NOTE: isdigt only works with characters
                // to check if st.top() is digit (since st.top() is a str)
                // we accessed the 0th char of the str
                // this is bcuz we know that it is always going to be single len str
                string k = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }

                // decode the string and push to stack
                string decoded_string = "";
                int ktimes = stoi(k);
                while(ktimes) {

                    decoded_string += encoded_string;
                    ktimes--;
                }
                st.push(decoded_string);
            }

        }

        // now the stack contains multiple strings
        // we need to convert it into a single string
        string res = "";
        while(!st.empty()) {

            string temp = st.top();
            res = temp + res;
            st.pop();
        }

        return res;
    }
};