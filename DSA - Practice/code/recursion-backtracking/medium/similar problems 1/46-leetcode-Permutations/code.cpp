/*

for every possible position, we should have every possible element

recursion:
solve(index,) {

    // base condition: when index >= nums.size()
    finalAns.push_back(currentArr)

    for(every element in nums) {
        currentArr.push_back(nums[index])
        solve(index+1)
        currentArr.pop_back()
    }

}

TC: O(n!∗n)
SC: O(n)

*/

class Solution {

    void solve(vector<int>& nums, int index, vector<bool> picked, vector<int> current, vector<vector<int>>& finalAns) {

        // base condition
        if(index >= nums.size()) {
            finalAns.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!picked[i]) {

                current.push_back(nums[i]);
                picked[i] = true;

                solve(nums, index+1, picked, current, finalAns);
                
                picked[i] = false;
                current.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> current;
        vector<vector<int>> finalAns;
        vector<bool> picked(nums.size(), false);

        solve(nums, 0, picked, current, finalAns);
        return finalAns;
    }
};