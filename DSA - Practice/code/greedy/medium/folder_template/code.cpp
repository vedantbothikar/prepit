/*

Problem Link: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

ChatGPT: https://chatgpt.com/share/68f2daf6-4eb0-8012-89f0-e94f12ea98f6

NOTE: This is complex to understand, so do chatgpt to understand it well.

NOTE: If you use maxheap, it will give TLE because of the large constraints.


Explanation:
We use a greedy approach to sell the balls with the highest value first.
We sort the inventory in descending order and then iterate through it.
For each distinct value, we calculate how many balls we can sell at that value before moving to the next lower value.
We use a mathematical formula to calculate the sum of values between two heights to avoid time limit exceeded errors.
This approach ensures we maximize profit while handling large constraints efficiently.

Time Complexity: O(n log n) due to sorting the inventory.
Space Complexity: O(1) as we are using only a constant amount of extra space.

*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {

    ll MOD = 1000000007;

    /*
        We find the sum till H1 and sum till H2
        and then subtract them to get the sum between H1 and H2
    */
    ll sumBtwnH1andH2(ll H1, ll H2) {

        // using formula sumTillN = n*(n+1)/2
        ll sumTillH1 = (H1 * (H1+1)) / 2;
        ll sumTillH2 = (H2 * (H2+1)) / 2;

        return sumTillH1 - sumTillH2;
    }

public:
    int maxProfit(vector<int>& inventory, int orders) {
        
        // sort in descending order
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0); // for safety

        ll maxProfit = 0;
        int n = inventory.size();
        ll k = 1;   // no. of colors at current highest level


        for(int i = 0; i < n - 1; i++) {

            if(orders <= 0) break;


            ll H1 = inventory[i];   // first highest
            ll H2 = inventory[i+1]; // second highest
            ll diff = H1 - H2;

            ll possibleBalls = k * diff;    // total possible balls we can take

            if(possibleBalls <= orders) {

                // take all possible Balls
                ll sumH1toH2 = sumBtwnH1andH2(H1, H2);
                ll sumOfKGroups = k * sumH1toH2;

                maxProfit += sumOfKGroups;
                orders -= possibleBalls;
            }
            else {

                // if we can't take all possible balls

                ll fullGroups = orders / k;
                ll remainingBalls = orders % k;

                if(fullGroups > 0) {

                    // now we need to sum from H1 to (H1 - fullGroups)
                    ll newH1 = H1;
                    ll newH2 = H1 - fullGroups;
    
                    ll sumH1toH2 = sumBtwnH1andH2(newH1, newH2);
                    ll sumOfKGroups = k * sumH1toH2;

                    maxProfit += sumOfKGroups;
                }

                if(remainingBalls > 0) {

                    ll newHighestLevel = H1 - fullGroups;
                    ll val = newHighestLevel * remainingBalls;

                    maxProfit += val;
                }

                orders = 0; // since we took all possible balls now
            }

            // move to next distinct value: increase k to include inventory[i+1]
            k++;    // now there is one more color of same count
        }

        return maxProfit % MOD;
    }
};