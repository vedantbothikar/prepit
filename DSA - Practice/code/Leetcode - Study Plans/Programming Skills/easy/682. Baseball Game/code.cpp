/*

- https://leetcode.com/problems/baseball-game/?envType=study-plan-v2&envId=programming-skills

*/


class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        vector<int> ans;
        for(string op : operations) {

            int n = ans.size();
            if(op == "+") {
                int temp = ans[n-1] + ans[n-2];
                ans.push_back(temp);
            }
            else if (op == "D") {
                int temp = ans[n-1] * 2;
                ans.push_back(temp);
            }
            else if(op == "C") {
                ans.pop_back();
            }
            else {
                ans.push_back(stoi(op));
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};