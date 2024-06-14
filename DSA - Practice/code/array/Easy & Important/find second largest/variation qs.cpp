/*

HERE THE PROBLEM STATEMENT IS SLIGHTLY DIFFERENT:
https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM


# APPROACH:

First reduce the scope for simplicity:
Lets say we want to find the second largest element

Now we know that we can find the largest element by O(N)
    - By traversing the whole array by maintaing a variable

Follow similar approach for other elements as well
by maintaining a variable for each one of them

Just need to add if conditions on when to update those variables

T.C. = O(N)


NOTE:
HERE in this question it is mentioned that the array has n unique numbers
and all of them are non-negative and the min. size of array is 2

So there are very less edge cases here, unlike:
https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest
In this GFG problem there are many edge cases, for example:
5,5
5,5,2
5,5,5,5,5
5
and so on...


*/


vector<int> getSecondOrderElements(int n, vector<int> arr) {
    	    
    	int largest = max(arr[0], arr[1]);
        int sec_large = min(arr[0], arr[1]);

        int smallest = sec_large;
        int sec_small = largest;

        vector<int> ans;
        
        if(n == 2) {
        
            ans.push_back(sec_large);
            ans.push_back(sec_small);
            return ans;   // CASE: example 5,6  -> 5 is second largest
        }
        
        // From here, it is taken that no of elements are more than 2
        
        // Traverse
        for(int i=2; i<n; i++){
    
            if(arr[i] > largest) {
                
                sec_large = largest;
                largest = arr[i];
            }
            else if (arr[i] < smallest) {
                
                sec_small = smallest;
                smallest = arr[i];
            }
            else if(arr[i] > sec_large and arr[i] < largest) {
                sec_large = arr[i];
            }
            else if (arr[i] < sec_small and arr[i] > smallest) {
                sec_small = arr[i];
            }
        }
        
        ans.push_back(sec_large);
        ans.push_back(sec_small);

        return ans;

}
