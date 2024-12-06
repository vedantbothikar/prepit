/*

- https://leetcode.com/problems/gas-station/description/
- https://leetcode.com/problems/gas-station/editorial/

First, to even have a possible solution, the total sum of gas MUST be greater than or equal to the total sum of the cost. Or else how are you going to travel?
If this is not true, then just return -1

Now, 
When you choose a position, you keep on travelling
currGain += gas[i] - cost[i] 

And your currGain must always be >= 0
If it is not, then you will NOT be able to go ahead. 
So this is a kind of valley (the number we have traversed so far. The solution does NOT lie here)
Why? 
Consider we start from index = 0, and we reach a point where we cannot go ahead. Now in all of the previous points, we had something positive with us (or may be 0), with which we went ahead and checked if we could go ahead. Now if we start with any point in between this segment (segment is the startpoint and the point where we failed to go ahead), then we have ALREADY checked if we are able to go ahead with already something as positive, and since we were NOT able to, that means if we start from any point in between, (and that way we have intially 0 gas) then we would DEFINITELY NOT go ahead of the valley point (point where we failed earlier).

So, better start from the point ahead of valleypoint.
(valleypoint means the point ahead of where it failed)



TC: O(N)
SC: O(N)



*/
class Solution {

    int findValleyPoint(vector<int>& gas, vector<int>& cost, int start) {

        int n = gas.size();
        int currGain = 0;

        for(int i = start; i < n; i++) {

            int nextPos = (i + n) % n;
            currGain += gas[i] - cost[i];

            if(currGain < 0) {
                return i;
            }
        }

        // case: successfully complete the circle
        return -1;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        // base condition: check if possible solution exists
        if(totalCost > totalGas) return -1;

        // Now a solution definitely exists

        for(int i = 0; i < n; i++) {

            cout << "loop infinity" << endl;

            int valleyPoint = findValleyPoint(gas, cost, i);

            // valid answer found
            if(valleyPoint == -1) return i;

            // start from new position
            i = valleyPoint;
        }

        // program will ideally never reach here
        return -1;
    }
};