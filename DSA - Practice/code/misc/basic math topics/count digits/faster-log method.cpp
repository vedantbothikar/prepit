// Log based C++ program to count number of
// digits in a number
#include <bits/stdc++.h>
using namespace std;


/*

https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/

Log-based Solution to count digits in an integer
We can use log10(logarithm of base 10) to count the number of digits of positive numbers (logarithm is not defined for negative numbers).
Digit count of N = upper bound of log10(N). 

Below is the implementation of the above idea:

Time Complexity: O(1) or constant
Auxiliary Space: O(1) or constant

This is a better approach as it takes constant time

*/


int countDigit(long long n) { 
  return floor(log10(n) + 1); 
}

// Driver code
int main(void)
{
    long long n = 345289467;
    cout << "Number of digits : " 
         << countDigit(n);
    return 0;
}
