/*

nums [1,2,3,4]
prefix [1, 1, 2, 6]
suffix [24, 12, 4, 1]

ans = [1*24, 1*12, 2*4, 6*1]
(multiplication of prefix and suffix arrays)


HOW to make prefix: 
- prefix[0] will always be 1
- prefix[i] = prefix[i-1] * arr[i-1]
for last element also it would work fine

HOW to make suffix:
we should be starting from end to start
i from end to 0
- suffix[end] = 1 => ALWAYS
- suffix[i] = suffix[i+1] * arr[i+1]
should work fine for 0th element

ans 
for i 0 to end:
    ans[i] = prefix[i] * suffix[i]



*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {

        int n = arr.size();

        // populate prefix
        vector<int> prefix(n, 1);
        prefix[0] = 1;
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * arr[i-1]; 
        }

        // populate suffix
        vector<int> suffix(n, 1);
        suffix[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * arr[i+1];
        }

        // populate ans
        vector<int> ans;
        for(int i =0; i < n; i ++) {

            int value = prefix[i] * suffix[i];
            ans.push_back(value);
        }
        
        return ans;
    }
};