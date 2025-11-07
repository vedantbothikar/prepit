class Solution {

public:
    vector<int> frequencySort(vector<int>& nums) {
        
        // create a freq map
        // num -> freq
        unordered_map<int, int> freq; 
        for(int num : nums) {
            freq[num]++;
        }

        // now that we have the frequencies
        // we just neeed to apply the custom sort logic
        // Custom sort logic:
        // first sort by frequencies in ascending order
        // if condition not satisfied: 
        // sort with descending value order
        sort(nums.begin(), nums.end(), [&](int a, int b) {

            if(freq[a] == freq[b]) return a > b;

            return freq[a] < freq[b];
        });

        return nums;
    }
};  