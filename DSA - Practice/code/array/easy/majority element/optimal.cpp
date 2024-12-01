#include <bits/stdc++.h>


/*

OPTIMAL SOLUTION:

Striver video:
https://www.youtube.com/watch?v=nP_ns3uSh80&ab_channel=takeUforward

- Check explanation of all solutions: https://leetcode.com/problems/majority-element/solutions/3676530/3-method-s-beats-100-c-java-python-beginner-friendly/


APPROACH:

- Apply Moore's Voting algorithm
- Verify if the element is actually the majority element

NOTE: For this leetcode problem it is mentioned in the problem description that
we can assume there exists a majority element always, so there is no need to
verify if the element we have found using Moores Algorithm is major or not


Moore's Voting Algorithm:

// consider the first element
element = arr[0]
count = 1



- Go to the next element
- If it is equal to the current element, then increment the count
- Else, decrement
- Whenever count becomes 0, the you need to start over, because there was no
conclusion of major element so far in the previous sub array


TC: O(N)
SC: O(1)



*/

int findMajorityElement(int nums[], int n) {
  int element = nums[0];
  int count = 1;

  // Apply Moore's Algorithm
  for (int i = 1; i < n; i++) {

    if (count == 0) {
      element = nums[i];
      count = 1;
      continue;
    }

    if (nums[i] == element) {
      count++;
    } else {
      count--;
    }
  }

  count = 0;
  // Verify the element
  for (int i = 0; i < n; i++) {

    if (nums[i] == element) count++;
  }

  return count > floor(n / 2) ? element : -1;
}