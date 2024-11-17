#include<bits/stdc++.h>
using namespace std;

/*

https://www.geeksforgeeks.org/problems/introduction-to-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-trees

HOW TO FIND THE NUMBER OF NODES ON A CERTAIN LEVEL?



*/



class Solution {
  public:
    int countNodes(int i) {
        // your code here
        
        return pow(2, i-1);
    } 
};

int main () {


    return 0;
}