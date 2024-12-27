/*

- https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
- https://neetcode.io/solutions/merge-triplets-to-form-target-triplet

Observation is such that if there is a triplet that has any of its value greater than the target's any values, then that is an invalid triplet and it is not at all useful. So we can ignore it completely.

Now what are useful are the triplets which have less than or equal to the values of the target. From these triplets what we only have to do is to check if ANY of the triplets have the values of the target. This is because if we combine (do the max operation) on any of those triplets which have less than or equal to target values we are going to get the max value as the ones in the target


TC: O(N)
SC: O(1)

*/
class Solution {

    bool validTriplet(vector<int> triplet, vector<int>& target) {

        for(int i = 0; i < 3; i++) {
            if(triplet[i] > target[i]) return false;
        }

        return true;
    }

public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<bool> ans = {false, false, false};
        for(auto triplet : triplets) {

            if(!validTriplet(triplet, target)) continue;

            for(int i = 0; i < 3; i++) {

                if(triplet[i] == target[i]) ans[i] = true;
            }
        }

        return ans[0] && ans[1] && ans[2];
    }
};