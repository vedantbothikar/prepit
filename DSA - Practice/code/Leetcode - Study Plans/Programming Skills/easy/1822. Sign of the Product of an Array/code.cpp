/*
- https://leetcode.com/problems/sign-of-the-product-of-an-array/?envType=study-plan-v2&envId=programming-skills
- 1822. Sign of the Product of an Array

we dont have to find the product. we can just calculate the number of negatives
if there is any zero, just return 0 straightaway

if the number of negatives are odd then result will be negative, and vice versa


*/
class Solution {
public:
    int arraySign(vector<int>& nums) {

        int negatives = 0;
        for(int num : nums) {
            if(num == 0) return 0;
            if(num < 0) negatives++;
        }

        if(negatives % 2 == 1) return -1;
        return 1;
    }
};