#include <bits/stdc++.h>
using namespace std;


/*


https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/

We can convert the number into a string and then find the length of the string to get the number of digits in the original number.

Note: It gives TLE for numbers other than range of int,example long and long long .

Time Complexity: O(1) or constant
Auxiliary Space:  O(Number of digits in an integer)


*/



// To count the no. of digits in a number
void count_digits(int n)
{
    // converting number to string using
    // to_string in C++
    string num = to_string(n);

    // calculate the size of string
    cout << num.size() << endl;
}
//Driver Code
int main()
{
    // number
    int n = 345;
    count_digits(n);
    return 0;
}
