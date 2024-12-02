/*

- https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array
- https://takeuforward.org/data-structure/leaders-in-an-array/

Traverse from the right side,
 keep a track of the maxelement
 as you move leftward, if any element is greater or equal
 to the maxelement, that is a leader


*/

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        if(n == 0) return {};
        
        vector<int> ans;
        int maxEle = arr[n-1];
        
        for(int i = n-1; i >= 0; i--) {
            
            if(arr[i] >= maxEle) {
                
                ans.push_back(arr[i]);
                maxEle = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};