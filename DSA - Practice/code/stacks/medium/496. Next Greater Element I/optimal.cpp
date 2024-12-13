/*


Maintain a stack
- if the element at top of stack is less than the currElement, then keep popping since we have found our next greater element
    - in a hashmap store the int, int <elemnt, nextGreaterEle>
- if the currElement is smaller than the stack top, then just push to stack


Do this for all elements in nums2

TC: O(n + m)
SC: O(n)

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map <int, int> mp;
        stack<int> s;
        
        for(int currNum : nums2) {

            // if top is < currNum
            if(!s.empty() && s.top() < currNum) {

                // pop elements until top is greater
                while(!s.empty() && s.top() < currNum) {
                    
                    int temp = s.top();
                    mp[temp] = currNum;
                    s.pop();
                }

                s.push(currNum);
            }
            else {
                // top > currNum: push currNum to stack
                s.push(currNum);
            }

        }

        // pop all stack elements, since they have no greater Ele
        while(!s.empty()) {
            int temp = s.top();
            mp[temp] = -1;
            s.pop();
        }

        // populate the values in an ans array
        vector<int> ans;
        for(int num : nums1) {

            ans.push_back(mp[num]);
        }

        return ans;
    }
};