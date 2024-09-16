/*

- problem: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
- solution: https://www.youtube.com/watch?v=1ibsQrnuEEg
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    static bool comparison(Item a, Item b) {
        
        return (
            ((double)a.value / a.weight)
            >
            ((double)b.value / b.weight)
            );
    }
    
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        // sort according to the value per weight
        sort(arr, arr + n, comparison);
        double ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(arr[i].weight <= w) {
                w -= arr[i].weight;
                ans += arr[i].value;
            }
            else {
                double fraction = (double)arr[i].value / arr[i].weight;
                double possibleWeight = w * fraction;
                ans += possibleWeight;
                break;  // since we got the answer
            }
        }
        
        return ans;
    }
};