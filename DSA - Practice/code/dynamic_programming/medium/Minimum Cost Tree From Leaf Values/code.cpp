/*


- problem: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
- solution: https://youtu.be/LDiD9fr28tc?si=63VVIHQ8T3PvcT_w
- explanation: https://gist.github.com/vedantbothikar/7894f48d7e13b71489175c9cc906bb76

*/


class Solution {

    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& maxLeaf) {

        // base case
        if(i == j) {
            return 0;
        }

        // check in dp
        if(dp[i][j] != -1) return dp[i][j];

        // logic
        // find the min cost of i to j amongst breakpoints from k=0 to j-1
        int minCost = INT_MAX;
        for(int k = i; k < j; k++) {

            int leftCost = solve(arr, i, k, dp, maxLeaf);
            int rightCost = solve(arr, k+1, j, dp, maxLeaf);

            int currentCost = leftCost + rightCost + (maxLeaf[i][k] * maxLeaf[k+1][j]);
            minCost = min(minCost, currentCost);
        }

        return dp[i][j] = minCost;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> maxLeaf(n, vector<int>(n, 0));

        // populate maxLeaf
        for(int i = 0; i < n; i++) {

            maxLeaf[i][i] = arr[i];
            for(int j = i+1; j < n; j++) {

                maxLeaf[i][j] = max(maxLeaf[i][j-1], arr[j]);     // comparison between max so far and the new element that we are considering now
            }
        }

        return solve(arr, 0, n-1, dp, maxLeaf);
    }
};