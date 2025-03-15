/*

- https://leetcode.com/problems/majority-element-ii/
- Neetcode: https://youtu.be/Eua-UrQ_ANo?si=N_nvrJ4wmcq6J0j5

NOTE: There are simpler solutions like 
TC: O(N)
SC: O(N)
(using hashmap)

But below solution is a follow up solution of Leetcode where they asked to solve it in constant space.



num1 
count1

num2 
count2

if count1 == 0
    num1 = currEle
    count1 = 1
    continue
else if count2 == 0
    similar
    continue
else if currEle != num1 and currEle != num2:
    count1--
    count2--
else if currEle == num1:
    count1++
else if currEle == num2:
    count2++


TC: O(N)
SC: O(1)


*/
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            
            int len = nums.size();
            if(len == 1) return {nums[0]};
    
            // random initialize
            long num1 = LONG_MAX;
            int count1 = 0;
    
            long num2 = LONG_MAX;
            int count2 = 0;
    
            for(int i = 0; i < nums.size(); i++) {
    
                int currEle = nums[i];
    
                if(currEle == num1) {
                    count1++;
                }
                else if(currEle == num2) {
                    count2++;
                }
                else if (count1 == 0) {
                    num1 = currEle;
                    count1 = 1;
                }
                else if(count2 == 0) {
                    num2 = currEle;
                    count2 = 1;
                }
                else if(currEle != num1 and currEle != num2) {
                    count1--;
                    count2--;
                }
            }
    
            // now verify if num1 and num2 are the correct solutions
            
            if(count1 == 0 and count2 == 0) return {};
    
            count1 = 0;
            count2 = 0;
            for(int curr : nums) {
                
                if(curr == num1) {
                    count1++;
                }
                else if(curr == num2) {
                    count2++;
                }
            }
    
            vector<int> ans;
            if(count1 > len/3) {
                ans.push_back(num1);
            }
            if(count2 > len/3) {
                ans.push_back(num2);
            }
    
            return ans;
        }
    };