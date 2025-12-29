/*

227. Basic Calculator II
https://leetcode.com/problems/basic-calculator-ii/description/

(helpful video)
Optimized solution without extra space: https://www.youtube.com/watch?v=W3Rg4HVSZ9k


Use stack. (using extra space here)
If operator like + or -, just push the number into the stack

If operator like * or /: do the operation right now with the top of the stack and currNum


TC: O(N)
SC: O(N)


*/
class Solution {
public:
    int calculate(string s) {

        int n = s.size();
        char currOp = '+';  // initially we will have currOp as plus
        stack<int> st;

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            // ignore if whitespace
            if(ch == ' ') continue;

            if(isdigit(ch)) {

                // if digit: get the entire number
                // Eg: could be 334 and we just got 3 for now
                int currNum = 0;
                while(i < n && isdigit(s[i])) {

                    currNum = (currNum * 10) + (s[i] - '0');
                    i++;
                }
                i--;    // to adjust back to last digit position

                // now we got the entire number
                // apply the operation 
                
                if(currOp == '+') {
                    
                    st.push(currNum);
                }
                else if(currOp == '-'){
                    
                    st.push(-currNum);   // IMP
                }
                else if(currOp == '*') {

                    // pop the top: apply operation: then push
                    int top = st.top();
                    st.pop();
                    int val = top * currNum;
                    st.push(val);
                }
                else if(currOp == '/') {

                    // pop the top: apply operation: then push
                    int top = st.top();
                    st.pop();
                    int val = top / currNum;
                    st.push(val);
                }
            }
            else {

                // only other possible char is an operator
                // update currOp
                currOp = ch;
            }
        }

        // add all the values inside the stack
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res; 
    }
};