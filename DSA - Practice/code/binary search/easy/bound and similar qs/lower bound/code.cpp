/*

We need to find an element such that it has the lowest index that satisfies the condition of
being equal to greater than the target element

index i where arr[i] >= x

since it is sorted we have a hint that we can use binary search here
so we just need to find the element that is arr[i] >= x
but the only condition is that the index should be the smallest


VIDEO: https://www.youtube.com/watch?v=6zhGS79oQ4k

________________________________

NOTE:

In coding rounds, you can use CPP STL function to find the lower bound as below:
(ChatGPT if you need help)

    std::vector<int> vec = {1, 3, 5, 7, 9, 11}; // Sorted vector
    int value = 5;

    // Find the lower bound
    auto lower = std::lower_bound(vec.begin(), vec.end(), value);

    // Get the index by subtracting the iterator from vector's begin
    int index = lower - vec.begin();

    // Output the results
    std::cout << "Lower bound of " << value << " is at index: " << index << std::endl;
    



*/



int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	int start = 0;
	int end = n-1;
	int ans = n;

	while(start <= end) {

		int mid = start + (end - start)/2;

		if(arr[mid] >= x) {
			ans = mid;	// this probably could be an answer
			end = mid - 1;
		}
		else {
			// now since the arr[mid] element is smaller that x, we need to search in the right side
			start = mid + 1;
		}
	}

	return ans;
}
