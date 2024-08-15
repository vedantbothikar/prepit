/*

sorted array so we can use binary search



*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.

	int start = 0;
	int end = n-1;
	int floor = -1;

	while(start <= end) {

		int mid = start + (end - start)/2;

		if(a[mid] <= x){
			floor = a[mid];
			start = mid +1;
		}
		else {
			end = mid - 1;
		}
	}


	start = 0;
	end = n-1;
	int ceil = -1;

	while(start <= end) {

		int mid = start + (end - start)/2;

		if(a[mid] >= x){
			ceil = a[mid];
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return {floor, ceil};

}