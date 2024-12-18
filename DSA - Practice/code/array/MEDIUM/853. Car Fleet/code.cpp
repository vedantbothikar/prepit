/*

- https://leetcode.com/problems/car-fleet/
- https://neetcode.io/solutions/car-fleet

The logic is that you calculate the time taken for each car to reach the target.
And based on that you can find the fleets.

But, first to solve this problem, you need to sort the cars based on their current position in DESCENDING order. Why? because whatever car is behind will join the car ahead, and this will determine a fleet. This method will reduce complications.
For more info read hints at: https://neetcode.io/solutions/car-fleet

And now that you have a pair of array sorted in descending based on the positions, find the time required for each car.
If the time required for current car to reach target is SMALLER than the time required for car ahead of it, that means the car behind will reach the car ahead eventually, and form a fleet.
So if the time required by current car is NOT SMALLER (which means greater) than the time required for car ahead of it, that means the current car will have a separate fleet.

How to find the time required for a car to reach target?
time = (target - currPos) / speed

TC: O(n)
Space complexity: O(n)    // for the vector of pair

*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // create a vector of pair of position and speed
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // sort in ascending based on position
        sort(cars.begin(), cars.end());

        // traverse from the behind, in decreasing order of position
        int n = cars.size();

        int totalFleets = 1;

        // find time of last car and store as prevTime
        double prevTime = (double)(target - cars[n-1].first) / cars[n-1].second;
        for(int i = n-2; i >= 0; i--) {

            double currTime = (double)(target - cars[i].first) / cars[i].second;
            // if the car ahead reaches in less time (meaning those 2 cars DONT meet)
            if(currTime > prevTime) {

                totalFleets++;
                prevTime = currTime;            
            }
        }

        return totalFleets;
    }
};