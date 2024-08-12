#include<bits/stdc++.h>
using namespace std;


/*
PROBLEM: 
https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest


*/

	int print2largest(int arr[], int n) {
	    
    	// base case when there are only 1 element
        if(n == 1) return -1;    
    	    
    	int largest = max(arr[0], arr[1]);
        int sec_large = min(arr[0], arr[1]);
        
        if(n == 2) {
        
            if(largest == sec_large) return -1;     // CASE: example 5,5 there is no second largest here
            
            return sec_large;   // CASE: example 5,6  -> 5 is second largest
        }
        
        // From here, it is taken that no of elements are more than 2
        
        // Traverse
        for(int i=2; i<n; i++){
            
            if(largest == sec_large) {  // CASE: When 5,5,5,2 then large and sec_large are equal initially, so if this if condition is not there, then sec_large would never be updated to any other value... so... BUT if it is 5,5,5,5,5 then if sec_large till the end stays the same as largest, then at bottom before returning we have a logic for this
                
                sec_large = arr[i];
            }
    
            if(arr[i] > largest) {
                
                sec_large = largest;
                largest = arr[i];
            }
            
            else if (arr[i] < largest and arr[i] > sec_large){
                
                sec_large = arr[i];
            }
        }
        
        if(largest == sec_large) return -1;     // CASE: 5,5,5,5,5,5

        return sec_large;
	    
	}