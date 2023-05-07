#include <bits/stdc++.h>
using namespace std;

/*

ARRAYS

https://www.codingninjas.com/codestudio/problems/find-student_3161883?topList=jp-morgan-interview-questions

*/

#include <bits/stdc++.h>

/*


find first occurrence of a value
use binary search
if doesnt exist, return -1


- we will search in the region from start to (H-start)/K


*/

int findPos(int N, int K, int H, vector<int> &A)
{
    // Write your code here.

    for (int i = 0; i < N; i++)
    {

        if (A[i] == H)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    return 0;
}