/*

- https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398


*/


/*
Approach:
- First we will find the the list of sums of all 
subarrays O(N^2)
- Sort, this sumsArray
	- Then take the value of kth position from last
		- (n-k)th value

TC: O(n^2)
SC: O(n^2) // because the array will store the sums of all subarrays


Approach:
 We can reduce the space complexity to O(k) by using minheap

So we already know how to find the kth largest element in any array using minheap
And this takes 
	TC: O(n*logk) 
	SC: O(k)	// k will be smaller than n^2 of the previous approach
*/


#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.

	priority_queue<int, vector<int>, greater<int>> pq;

	int n = arr.size();
	for(int start = 0; start < n; start++) {

		int currSum = 0;
		for(int end = start; end < n; end++) {

			currSum += arr[end];

			// add to minheap
			pq.push(currSum);
			if(pq.size() > k) {
				pq.pop();	// this logic will pop the smallest element. So essentially at the end, minheap will have the k largest elements. And since it is a minheap, the smallest of those will be at the top. So we can get the kth largest element by accessing the top of the minheap
			}
		}
	}


	return pq.top();
}