#include<bits/stdc++.h>
using namespace std;

/*
- This is the simplest way to count the number of digits in a number
- This takes O(numberOfDigits) time for running

- This approach can be improved.


https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
*/


int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

// Driver code
int main(void)
{
    long long n = 345289467;
    cout << "Number of digits : " << countDigit(n);
    return 0;
}