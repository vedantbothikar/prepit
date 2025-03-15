/*

- https://leetcode.com/problems/range-sum-query-2d-immutable/
Neetcode: https://youtu.be/KE8MQuwE2yA

Prefix Sum:
We will calculate the prefix of squares. We will first consider each element as the bottomRight corner of a square and calculate the sum of the corresponding square from (0,0)

And now when we want to calculate the sum of any given square, we will just do:

bottomRight - topArea - leftArea + topLeft

Note: we add topLeft because it will be subtracted twice (both from topArea and leftArea)


Pre-computation:
For every row:
    For every col:
        considering this element as bottomRight, calculate the sum of this square


How to do this:
    considering this element as bottomRight, calculate the sum of this square
=> 

We need to understand that we will be having the sum of elements in the square above this row. 
So we just need to calculate the prefix of this current row and add to that the sum of the square above it
(Watch video for better understanding)

So,
For every row:
    For every col:
        prefix += givenMatrix[row][col]

        aboveSqSum = sumMatrix[row-1][col]
        sumMatrix[row][col] = prefix + aboveSqSum



TC: O(m*n) for precomputation
SC: O(m*n)



*/
class NumMatrix {

    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& mat) {

        int totRows = mat.size();
        int totCols = mat[0].size();

        totRows += 1;
        totCols += 1;

        // initialize sumMat with 0 (having 1 row and 1 col extra than mat)
        sumMat = vector<vector<int>>(totRows, vector<int>(totCols, 0));

        // looping on sumMat to precompute
        // calculate the prefix: every ele considered as bottomRight of its
        // corresponding square
        for(int row = 1; row < totRows; row++) {

            int prefix = 0;
            for(int col = 1; col < totCols; col++) {

                // now since we are getting the element in mat, we need to 
                // reduce the indices by 1 to actually get (row, col)
                prefix += mat[row-1][col-1];

                // get the sum of the square above it
                int aboveSumSq = sumMat[row-1][col];
                
                sumMat[row][col] = prefix + aboveSumSq;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // add 1 to all because our new sumMat has one additional row and col
        // so new values of row1,col1 etc will be added by 1 to get the correct indices
        row1 = row1 + 1;
        row2 = row2 + 1;
        
        col1 = col1 + 1;
        col2 = col2 + 1;

        int bottomRight = sumMat[row2][col2];
        
        int leftArea = sumMat[row2][col1-1];
        int aboveArea = sumMat[row1-1][col2];

        int topLeft = sumMat[row1-1][col1-1];

        return bottomRight - leftArea - aboveArea + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */