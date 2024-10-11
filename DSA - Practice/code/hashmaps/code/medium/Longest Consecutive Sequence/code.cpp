/*

put all elements in the set

loop through the set
    when the currelement's previous is present in the set, do nothing
    when a new starting is element is found:
        while(set.count(arr[i]) != 0) count++ i++ 
    
    maxCount = max(maxCount, count);

Time: O(N)
Space: O(N)

*/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        int n = arr.size();

        // base case when n == 0
        if(n == 0) return 0;

        // store all elements in set
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {

            s.insert(arr[i]);
        }

        int count = 0;
        int maxCount = INT_MIN;
        for(int number : s) {

            if(s.count(number-1) == 0) {    // fresh starting number (there is no previous number)
                
                while(s.count(number) != 0) {
                    count++;
                    number++;
                }

                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        
        return maxCount;
    }
};