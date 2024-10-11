/*

k most frequent means, top k most freqent elements


ORDERED SET:
ordered set of pair
    first: element of array
    second: count (frequency of the element)
custom comparator function for the set

at end just print the top k elements of the set
TC: O(NlogN) 
    because loop through all elements is O(N) and inserting in ordered set is O(logN)
SC: O(N)

OPTIMAL SOLUTION:

We will frist need to store the frequencies of elements
Hashmap
loop through all elements, and keep updating the frequency of the elements


frequency array
each element in the inner array is at an 
    index: signifies the frequency of the element
    elements in the array are elements with that particular frequency
[ [] [] [] ]

reverse traverse in frequency array
    take the top k elements from this


*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // populate frequencies
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {

            int currentElement = nums[i];
            mp[currentElement]++;
        }

        // create the frequency array
        vector<vector<int>> freqArr(n+1);
        for(const auto& [number, frequency] : mp) {

            int index = frequency;
            freqArr[index].push_back(number);
        }

        // reverse traverse the frequency Array
        vector<int> ans;
        int count = 0;
        for(int i = n; i >=0; --i) {

            for(int number : freqArr[i]) {
                
                ans.push_back(number);
                count++;
                if (count == k)return ans;
            }
        }
        
        return {};
    }
};