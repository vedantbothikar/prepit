/*

- problem: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Problem Restatement:
You are given an array time[], where each element represents the duration of a song in seconds. You need to find how many pairs of songs (i, j), such that i < j, have their total duration divisible by 60. Formally, we want to count the number of pairs such that (time[i] + time[j]) % 60 == 0.

Approach:
Modular Arithmetic:

For each song duration time[i], compute time[i] % 60 (let's call this remainder r). This gives the remainder when the song duration is divided by 60.
For two songs to have their sum divisible by 60, their remainders when divided by 60 must add up to 60. For example:
If the remainder of the first song is r, the remainder of the second song must be 60 - r.
Special case: If the remainder is 0, it pairs with other songs that also have a remainder of 0 (i.e., the sum of both durations should be exactly divisible by 60).
Counting Complementary Pairs:

Use an array remainder[] of size 60 to track how many songs have each remainder from 0 to 59.
For each new song time[i], check how many previously seen songs have a complementary remainder that, when added to time[i] % 60, results in a sum divisible by 60.
After checking, update the remainder array to include the current song.
Algorithm:
Initialize an array remainder[60] to track the count of each remainder.
For each song duration in time[], calculate remainder = time[i] % 60.
If remainder == 0, count how many songs also have a remainder of 0 because they will form valid pairs.
For any other remainder r, check how many songs have a remainder of 60 - r, as they will form valid pairs.
After processing, update the remainder array with the current song's remainder.


*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        vector<int> remainder(61, 0);

        // loop through time, to update the hashmap count
        int count = 0;
        for(int i = 0; i < time.size(); i++) {

            int rem = time[i] % 60;
            int complement = (rem == 0) ? 0 : 60 - rem;

            count += remainder[complement];
            remainder[rem]++;
        }

        return count;
    }
};