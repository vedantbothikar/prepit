/*

Intuition
To solve this problem in O(n) time and constant extra space, we can utilize the fact that all integers in the array are in the range [1, n] and each integer appears once or twice. We can iterate through the array and use each element as an index to mark the corresponding element as negative. If we encounter an element that is already negative, it means we have seen it before and it's a duplicate.

Approach
Initialize an empty vector ans to store the duplicates.
Iterate through the array nums.
For each element nums[i], take its absolute value x.
Check if nums[x-1] is negative.
If it is, then x is a duplicate, so add it to ans.
Otherwise, mark nums[x-1] as negative.
Return ans.
Complexity
Time complexity:O(n)
Space complexity:O(k)
max value of k = n/2


*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};