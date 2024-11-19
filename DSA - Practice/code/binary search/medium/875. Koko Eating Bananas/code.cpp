

/*

- https://leetcode.com/problems/koko-eating-bananas/description/

Approach
check how mamy hours needed:
for every banana:
ans = ans + (1 + (bananas[i] / k))
return ans

bananas[i] / k = currentAns

ans will be from 1 to maxValue of the array
For each value in this range, check if it is an answer

How to check if it is the answer?
- if checkHowManyHoursNeeded == h

Complexity
Time complexity: O(n * logm)
Space complexity: O(1)


*/


using ll = long long;

class Solution {

    int getMaxElement(vector<int>& piles) {

        int maxEle = piles[0];
        for(int pile : piles) {
            if(pile > maxEle) {
                maxEle = pile;
            }
        }

        return maxEle;
    }

    // return the time taken to finish bananas with speed as k
    ll timeToFinishWithSpeedK(vector<int>& piles, int k) {

        ll timeToFinish = 0;
        for(int pile : piles) {
            
            if(pile % k == 0) { // if pile is perfectly divisible by k

                timeToFinish = timeToFinish + (pile / k);
            }
            else {  // if not, we will need an extra hour to finish the bananas
                
                timeToFinish = timeToFinish + (1 + (pile / k));
            }
        }

        return timeToFinish;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;
        int end = getMaxElement(piles);

        int ans = end;
        // Apply binary search on this range
        while(start <= end) {

            int mid = start + (end - start) / 2;

            // check if mid is a possible answer
            ll timeToFinish = timeToFinishWithSpeedK(piles, mid);

            if(timeToFinish <= h) {
                // we got a possible solution
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }   
};