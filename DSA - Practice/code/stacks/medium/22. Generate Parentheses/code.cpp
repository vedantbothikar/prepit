/*

- https://leetcode.com/problems/generate-parentheses/description/
- Watch: https://youtu.be/s9fokUqJ76A?si=AC0rC9kI9EIQ3lPk

*/

/*

Approach:

We need to understand that we will get our final solution when the number of open and close brackets are equal to the given number n (this we will check in the function)
But the parentheses must also be in correct order (this we will handle in the code logic)


Code logic:

Opening bracket logic:
We have to understand that it must always start with an open bracket.
So we must first add open brackets
And open brackets, at max can be added up to n 
So, as long as open < n we can do stuff
    - we append an opening bracket in the string 
    - recursively call the solve function for next bracket
    - remove the opening bracket for a possibility of closing bracket in next condition

Closing bracket logic:
Closing brackets will always appead only if there has been an opening bracket earlier. 
Therefore, open number of brackets must always be more in number than closing brackets.



*/

class Solution {

    void solve(int n, int open, int closed, string& current, vector<string>& ans) {

        // base condition when it is valid
        if(open == n and closed == n) {
            
            ans.push_back(current);
            return;
        }

        // we can add open bracket when open < n
        if(open < n) {

            current += '(';
            solve(n, open+1, closed, current, ans);
            current.pop_back();
        }

        // we can only add closing bracket when closed count is less than open
        if(closed < open) {

            current += ')';
            solve(n, open, closed+1, current, ans);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string current = "";

        solve(n, 0, 0, current, ans);
        
        return ans;
    }
};