/*

Taking extra space: 
we can have an array of rows and cols of size m and n respectively
Now while traversing the elements of the matrix, whenever an element is 0, then mark the row and col correspondingly in the rows and cols arrays 

When all traversal is completed, traverse again, but this time whenever you come across an element check if the row or col is present in the rows or cols arrays, if yes, then mark it as 0.

This takes 2 pass O(2n) and extra space O(m+n)


Without extra space:
I could consider the first row and col as the rows and cols arrays in the previous approach.

first traverse the 0th row and 0th col, if you find any 0, then mark 2 variables called zeroRow, zeroCol

What I have to do is that, traverse the matrix except for 1st row and 1st col, and whenever an element is 0, then mark the 0th row corresponding value and 0th col corresponding value as 0.

After traversing this, now traverse the smaller matrix again (which means traverse without 1st row and 1st col) and mark positions wherever the 0th row value or 0th col value is 0

if zeroRow is true, then mark first row as 0
if zeroCol is true then mark first col as 0


*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {

        int rowLen = mat.size();
        int colLen = mat[0].size();

        bool zeroRow = false;
        bool zeroCol = false;

        if(mat[0][0] == 0) {
            zeroRow = true;
            zeroCol = true;
        }

        // traverse 0th row
        for(int j = 0; j < colLen; j++) {
            if(mat[0][j] == 0) {
                zeroRow = true;
            }
        }

        // traverse 0th col
        for(int i = 0; i < rowLen; i++) {
            if(mat[i][0] == 0) {
                zeroCol = true;
            }
        }

        // traverse the smaller mat
        for(int i = 1; i < rowLen; i++) {

            for(int j = 1; j < colLen; j++) {

                if(mat[i][j] == 0) {
                    // mark the corresponding 0th row and 0th col as 0
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }

        // mark the values as 0 now
        for(int i = 1; i < rowLen; i++) {

            for(int j = 1; j < colLen; j++) {

                if(mat[0][j] == 0 or mat[i][0] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if(zeroRow == true) {

            // mark full 0th row as 0
            for(int j = 0; j < colLen; j++) {
                mat[0][j] = 0;
            }
        }

        if(zeroCol == true) {

            // mark full 0th col as 0
            for(int i = 0; i < rowLen; i++) {
                mat[i][0] = 0;
            }
        }
    }
};