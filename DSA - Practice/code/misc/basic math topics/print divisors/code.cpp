/*

Problem: https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188?leftPanelTabValue=PROBLEM

This is the brute force approach where we check for all number from 1 to n



*/



int* printDivisors(int n, int &size){
// Write your code here

    int *ans = new int[n];
    size = 0;
    for(int i=1; i <= n; i++){

      if (n % i == 0) {
        ans[size] = i;
        size++;
      }
    }

    return ans;
}
