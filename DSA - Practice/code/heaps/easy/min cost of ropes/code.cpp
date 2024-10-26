/*



- https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
- https://www.youtube.com/watch?v=_9F2VgZcvdw&t=1734s

*/

/*

The min cost will always be equal to the sum of the min values 
at the current state

*/


using ll = long long;

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        for(ll num : arr) {
            pq.push(num);
        }
        
        ll sum = 0;
        
        while(pq.size() > 1) {
            
            ll a = pq.top();
            pq.pop();
            
            ll b = pq.top();
            pq.pop();
            
            ll currSum = a + b;
            pq.push(currSum);   // Remember: to push the currSum to the pq
            
            sum += currSum;
        }
        
        return sum;
    }
};