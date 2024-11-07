/*

- https://leetcode.com/problems/single-number/description/

HOW DOES XOR OPERATION WORK?
-> Whenever XOR is performed on two same numbers, then XOR returns 0
But when it is applied on dissimilar numbers, then it returns something lese
And when XOR is performed on 0 and the number, then it returns the number itself


APPROACH:
- Traverse through all elements and perform XOR operation on all elements

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int current = 0;

        for(int i=0; i<nums.size(); i++) {

            current = current ^ nums[i];  // perform XOR operations
        }
        
        return current;
    }
};