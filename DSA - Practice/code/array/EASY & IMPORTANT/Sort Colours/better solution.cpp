#include<bits/stdc++.h>
using namespace std;

/*
Problem: https://leetcode.com/problems/sort-colors/description/

*/

/*

Better Solution (Not optimal): (Done in 2 passes with constant space)

APPROACH:
- Traverse the whole array once and while doing so, count the number of zeroes,
ones, and twos
- After counting, Traverse the whole array again once, and then replace the
first zeroes number of integers with 0, then next ones number of integers with 1
and similar for 2

This you can do in O(N) since you will be traversing the array 2 times
And this will be done in constant space

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zeroes = 0;
        int ones = 0;
        int twos = 0;

        // count integers
        for (int num : nums) {

            if (num == 0)
                zeroes++;
            if (num == 1)
                ones++;
            if (num == 2)
                twos++;
        }

        int index = 0;

        while (zeroes) {
            nums[index] = 0;
            index++;
            zeroes--;
        }

        while (ones) {
            nums[index] = 1;
            index++;
            ones--;
        }

        while (twos) {
            nums[index] = 2;
            index++;
            twos--;
        }
    }
};