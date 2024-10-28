/*

- https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379
- Q2: https://youtu.be/eccAKrmffh8?si=03MBsyLKGIvllYoP
*/

/*
- Push first k elements in the minheap
Step 2: - Check the top value
    - Push it in the ans array
- The value will be a pair 
    - array position (which array from the list of arrays)
    - index position (which position element in the array)
- After pushing the top in ans 
    - Pop the top from minheap
- Push new element of the array of which element was popped
    - array position we already know, index also we know, take the next element of this then, and push it to minheap
- Keep repeating Step 2 to Step 5



pair<int, pair<int, int>> p
p.first -> elementValue
p.second.first -> arrayNumber (which position of array is it?)
p.second.second -> elementPos (index value of the element in the array)

TC: O(n*k log(n*k))
SC: O(k)


*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    vector<int> ans;
    // IMPORTANT: Look at how I have declared the pq and how the comparator method is declared
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    // Push first elements of all k arrays in the pq
    for(int i = 0; i < k; i++) {
      pq.push({kArrays[i][0], {i, 0}});
    }

    while(pq.size() > 0) {

        // transfer the pq top to ans
        pair<int, pair<int, int>> p = pq.top();
        int elementValue = p.first;
        int arrayPos = p.second.first;
        int elementPos = p.second.second;
        
        ans.push_back(elementValue);
        pq.pop();

        // push next element into minheap
        int nextElementPos = elementPos+1;
        if(nextElementPos < kArrays[arrayPos].size()) {

            int nextElementVal = kArrays[arrayPos][nextElementPos];
            pq.push({nextElementVal, {arrayPos, nextElementPos}});
        }
    }

    return ans;
}
