/*

First think about how to find the next greater element of any element
- find the element in the nums2 
- traverse ahead from that element,
- whenever any element is greater, then return the index


if we have to do this for all nums1 elements,
then we will have to 
- for every element, start from the index, and keep searching ahead


TC: O(m*n)
SC: O(n)

*/
class Solution {

    int findNextGreater(vector<int> nums2, int num2, int startInd) {

        for(int i = startInd+1; i < nums2.size(); i++) {

            if(nums2[i] > num2) return nums2[i];
        }

        return -1;
    }

    void printMap(unordered_map<int, int> mp) {

        for(auto& [key, value] : mp) {
            cout << "num: " << key << " value: " << value << endl;
        }
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set <int> s;
        for(int num1 : nums1) {
            s.insert(num1);
        }

        unordered_map <int, int> mp;
        for(int i = 0; i < nums2.size(); i++) {

            int num2 = nums2[i];
            if(s.find(num2) != s.end()) {
                mp[num2] = i;
            }
        }

        printMap(mp);

        vector<int> ans;
        for(int num1 : nums1) {

            int startInd = mp[num1];
            int nextGreater = findNextGreater(nums2, num1, startInd);
            ans.push_back(nextGreater);
        }

        return ans;
    }
};