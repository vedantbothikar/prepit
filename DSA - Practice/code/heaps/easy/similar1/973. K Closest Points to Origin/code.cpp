/*

- https://leetcode.com/problems/k-closest-points-to-origin/description/

Approach:
- find the distance of all pairs with the origin, store then in an array called distance
- Take the k elements from this array (in ascending order)
TC:  
    O(N) to find all distances
        - we can put in minheap at same time. Push will be O(logn) which will be done N times
        - So overall time will be O(nlogn)
    
    - Retrieving k elements from the distance array will be O(k)
So, overall will be O(NlogN)
_____________

ALTERNATE:
We can use the strategy of finding the kth smallest number
So, here we can slightly modify it to something as giving k smallest numbers

- So, first we will loop through all points
- Check distance and put in maxheap (since we want k smallest)
    - size of maxheap will be k 
    - if the elements in maxheap are more than k, then pop
- At last, you have k smallest distance elements in the maxheap. Now just put them in an array and return

TC: O(N*logk)
Logk because the maxheap will take logk time since it's max size is k
 
SC: O(k)

priority_queue<pair<int, vector<int>>> maxpq;   
    - first: distance of x,y from 0,0
    - second: x,y stored for returning the answers later

NOTE:
 For integer squaring, directly multiply number by itself instead of using pow method. Reason? Check below article:
    - https://gist.github.com/vedantbothikar/bd1c7dcd8a785fe0965660eed082d27e

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq;   
        for(auto point : points) {

            int distance = point[0]*point[0] + point[1]*point[1];
            pq.push({distance, point});

            // logic to keep the smallest k elements in the pq
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};