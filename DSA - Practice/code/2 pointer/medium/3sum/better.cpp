/*

- problem: https://leetcode.com/problems/3sum/
- solution: 

fix one pointer which traverses every element of the arr
this fixation means that we are definitely considering this element for now, let's say this is i index

Now, we need to check if there exists 2 numbers in ahead of the array of which sum is 0 - arr[i]
    For this we will use 2 pointer approach on rest of the array

n = arr.size()
for(int i =0 to i=n-1-2){

    // 2 pointer approach on rest of the array
    start = i + 1
    end = n-1
    while(start < end){
        target = 0 - arr[i];
        if(arr[start] + arr[end] == target) {
            ans.push_back({i,start,end});
        }
    }
}

- Will we get duplicates in this?
    YES
        because we can have the same value at multiple positions inthe array
    HOW to avoid duplicates?
        we can have a set as the ans
        OR
        sort the array and skip duplicates
    
In this code file we will solve by skipping duplicates
Sort the array:

Sorting allows us to easily skip duplicate values (both for the i pointer and the two-pointer approach) and enables the two-pointer technique.
Skip duplicate values for i:

By checking arr[i] == arr[i - 1], we avoid fixing the same value multiple times for the first number in the triplet.
Two-pointer approach with duplicate skipping:

After finding a valid triplet (arr[i], arr[start], arr[end]), we skip over any duplicate values for both start and end to avoid generating duplicate triplets.
Move pointers accordingly:

After processing a valid triplet, increment start and decrement end to continue searching for other potential triplets.



*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int lastIndex = arr.size()-1;   // lastindex
        vector<vector<int>> ans;

        // sort the array
        sort(arr.begin(), arr.end());   // NOTE: sorting so that we avoid duplicates

        // check base cases when length is 0, 1, 2, or 3
        if(arr.size() == 0 or arr.size() == 1 or arr.size() == 2) return {};
        if(arr.size() == 3) {
            if(arr[0] + arr[1] + arr[2] == 0) {
                ans.push_back(arr);
                return ans;
            }
            else return {};
        }

        for(int i = 0; i < lastIndex-2; i++) {

            int start = i + 1;
            int end = lastIndex;
            int target = 0 - arr[i];

            // skip duplicates in i
            while(i < lastIndex-2-1 && arr[i] == arr[i+1]) i++;
            
            // 2 pointer approach
            while(start < end) {    // NOTE: we don't do start <= end because we cannot take the same element twice

                if(arr[start] + arr[end] == target) {
                    
                    ans.push_back({arr[i], arr[start], arr[end]});

                    // skip all next duplicates from start and end
                    while(start < end && arr[start] == arr[start+1]) start++;
                    while(start < end && arr[end] == arr[end-1]) end--;

                    start++;
                    end--;
                }
                else if (arr[start] + arr[end] < target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        
        return ans;
    }
};