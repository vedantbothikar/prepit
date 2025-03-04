/*

Problem: 
- https://leetcode.com/problems/merge-sorted-array/

Read solution here or use Editorial:
- https://gist.github.com/vedantbothikar/755b589adfdebfb62e4e61d52883075b


*/
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            
            int p1 = m-1;
            int p2 = n-1;
    
            for(int k = m+n-1; k >= 0; k--) {
    
                if(p2 < 0) break;
    
                if(p1 >=0 && nums1[p1] > nums2[p2]) {
                    
                    nums1[k] = nums1[p1];
                    p1--;
                }
                else {
    
                    nums1[k] = nums2[p2];
                    p2--;
                }
            }
        }
    };