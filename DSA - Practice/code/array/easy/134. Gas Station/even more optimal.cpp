/*
the code.cpp does it in O(n)
but that is actually O(2*n)

This below code also does it in O(n), but it actually does
it in a single pass. 

The totalGain inside the for loop is just for 
checking if the soltuion exists or not 
(which is the same as accumulate in my code.cpp)


You can also check this solution:
- https://leetcode.com/problems/gas-station/solutions/6003362/video-2-solutions-o-n-time-and-o-1-space



*/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGain = 0, totalGain = 0, answer = 0;

        for (int i = 0; i < gas.size(); ++i) {
            // gain[i] = gas[i] - cost[i]
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];

            // If we meet a "valley", start over from the next station
            // with 0 initial gas.
            if (currGain < 0) {
                answer = i + 1;
                currGain = 0;
            }
        }

        return totalGain >= 0 ? answer : -1;
    }
};