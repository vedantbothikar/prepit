/*

- https://leetcode.com/problems/search-a-2d-matrix/description/
- 

TC: O(log(m*n))
SC: O(1)


Consider all elements of the matrix as one flattened array of integers.
And now apply binary search on this single array

start = 0
end = (n*m)
mid = (start + end) / 2

Now that we got the mid element, we didnt actually get the row and col of the mid element.
We just go the position if the whole thing was flattened
But since it is not exactly flattened, we need to find the row and col from the position of mid element.
So,
row = mid / m;  // m is the total number of cols
col = mid % m;  

from this row and col we can now check if mat[row][col] == target
and accordingly apply binary search on this.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();
        int start = 0, end = (n*m)-1;

        while(start <= end) {

            int mid = start + (end - start) / 2;
            int midRow = mid / m;
            int midCol = (mid % m);

            if(mat[midRow][midCol] == target) {
                return true;
            }
            else if(mat[midRow][midCol] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }
};