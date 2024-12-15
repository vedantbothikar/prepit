/*

- https://leetcode.com/problems/continuous-subarrays/description/
- https://leetcode.com/problems/continuous-subarrays/editorial/

We will use a variable sliding window technique. 
As long as the window is valid, we will keep on adding elements 

But if the window is invalid, what we want to do is decrease the window length (slide the window)

Now as long as the window is valid, we want to add the no. of valid subarrays

suppose we currently have   1
                          ^l^r  
then valid subarrays will be 1

if we have 1, 2 now
           ^l ^r 
Then the valid subarrays will be total subarrays so far + the new subarrays formed by 2           
The total subarrays so far we had calculated (when there was only 1, was 1)
Now since 2 was added the new subarrays would be 2 and 1,2 which are new  (whic means 2 new subarrays)
So total now = 1 + 2 = 3


Now when we have 1 2 3
                ^l   ^r

Now again: 
Then the valid subarrays will be total subarrays so far + the new subarrays formed by 3
total prev subarrays = 3
New subarrays with 3 are:
[3], [2,3], and [1,2,3]   = total = 3
So new total = 3 + 3 = 6

You observe the whenever a new element is added it can form a continuous subarray with all prev elements once.
Like here 3 formed a continuous subarray with 
itself (3)
2,3
1,2,3

So if there is:
1,2,2,3
there will be 
[3], [2,3], [2,2,3], [1,2,2,3]
and so on

which means, everytime the the number of new subarrays that are being added is equal to the length of the new subarray (right-left+1)

So what we have to do is essentially:
as long as the subarray window is valid, keep adding the (right-left+1)

and whenever the window becomes invalid:
remove the left elements until the window is valid

How to check if a window is valid or not?
Use an ordered map, that stores the element and its frequency
to find the min element choose the first element
to find the max element choose the last element
and whenever the frequency of any element becomes 0, just erase it from the map

 
## Time complexity: O(nlogk)≈O(n)
The outer loop iterates through the array once with the right pointer, taking O(n) operations. For each element, we perform map operations (insertion, deletion, finding min/max) which take O(logk) time, where k is the size of the map. Since we maintain a window where the max−min≤2, the size of the sorted map k is bounded by 3 (as elements can only differ by 0, 1, or 2). Therefore, logk is effectively constant, making the overall time complexity O(n).

## Space complexity: O(k)≈O(1)
The sorted map stores elements within the current window. Since the difference between any two elements in a valid window cannot exceed 2, the maximum number of unique elements (k) possible in the map at any time is 3. Therefore, the space complexity is constant, O(1).



*/

using ll = long long;

class Solution {

    bool validWin(map<int, int>& freqmp) {

        int minEle = freqmp.begin()->first;
        int maxEle = freqmp.rbegin()->first;

        if(maxEle - minEle > 2) return false;

        return true;
    }

public:
    long long continuousSubarrays(vector<int>& nums) {

        map <int, int> freqmp;  // ordered map

        int n = nums.size();
        int left = 0, right = 0;

        ll total = 0;
        
        while(right < n) {

            // add curr element to map
            int currEle = nums[right];
            freqmp[currEle]++;

            // slide window if not valid
            while(!validWin(freqmp)) {

                int leftEle = nums[left];
                // remove left Element
                freqmp[leftEle]--;

                if(freqmp[leftEle] == 0) {
                    freqmp.erase(leftEle);
                }

                left++;
            }

            // add to the total no. of subarrays
            total += (right-left+1);
            
            right++;
        }

        return total;
    }
};