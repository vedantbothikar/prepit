/*

- https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays
- https://takeuforward.org/data-structure/union-of-two-sorted-arrays/


*/

class Solution {
    /*
    
    We will keep 2 pointers
    
    - whichever element is lesser than the other array's element, 
    we will insert that in the union array
    
    But to check if we already have added that element 
    in the past, we will keep checking the last element
    in the union array if it is equal to the element that we are
    currently trying to insert in the array
    
    At last insert all remaining elements of both the arrays
    
    TC: O(m+n)
    
    */
    
    
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        vector<int> unionArr;
        int k = -1;  // maintains the position of the last element in union array
        
        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        
        while(i < n && j < m) {
            
            if(a[i] <= b[j]) {
                
                // insert a[i]: only if last element in union is not equal
                if(k == -1 or unionArr[k] != a[i]) {
                    
                    unionArr.push_back(a[i]);
                    
                    i++;    // a ptr increment
                    k++;    // unionArr ptr increment
                }
                else {
                    
                    i++;    // last element was equal, so move ahead
                }
            }
            else {  // b[j] to be inserted
                
                if(k == -1 or unionArr[k] != b[j]) {
                    
                    unionArr.push_back(b[j]);
                    
                    j++;    // b ptr increment
                    k++;    // unionArr ptr increment
                }
                else {
                    
                    j++;    // last element was equal, so move ahead
                }
            }
            
        }
        
        // insert all remaining elements
        while(i < n) {
            
            if(k == -1 or unionArr[k] != a[i]) {
                
                unionArr.push_back(a[i]);
                i++;
                k++;
            }
            else {
                
                i++;
            }
        }
        
        while(j < m) {
            
            if(k == -1 or unionArr[k] != b[j]) {
                
                unionArr.push_back(b[j]);
                j++;
                k++;
            }
            else {
                
                j++;
            }
        }
        
        return unionArr;
    }
};
