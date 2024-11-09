class Solution {

    void solve(vector<int>& candidates, int target, int index, vector<int> currentAns, vector<vector<int>>& finalAns)    {

        // base case
        // when we hit the last number in the candidates array
        if(index == candidates.size()) {

            if(target == 0) {
                finalAns.push_back(currentAns);
            }
            return;
        }

        // pick or not pick
        // pick
        if(candidates[index] <= target) {
            currentAns.push_back(candidates[index]);
            solve(candidates, target-candidates[index], index, currentAns, finalAns);
            currentAns.pop_back();
        }
        // not pick
        solve(candidates, target, index+1, currentAns, finalAns);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> finalAns;
        vector<int> currentAns;
        solve(candidates, target, 0, currentAns, finalAns);
        return finalAns;
    }
};