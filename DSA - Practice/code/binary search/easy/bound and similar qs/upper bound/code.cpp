/*

the only difference between lower and upper bound question is that in upper bound we only check for arr[mid] > x which means element is strictly greater than x
and should not even be equal to x


VIDEO: https://www.youtube.com/watch?v=6zhGS79oQ4k

*/


int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	


	int start = 0, end = n-1;
	int ans = n;

	while(start <= end) {

		int mid = start + (end - start)/2;

		if(arr[mid] > x) {
			ans = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ans;
}