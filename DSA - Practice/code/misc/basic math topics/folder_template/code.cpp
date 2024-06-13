#include<iostream>
using namespace std;

/*

PROBLEM:
https://www.naukri.com/code360/problems/check-prime_624674?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM

NOTES:
Usually we think that the definition of prime number is that
"A prime number is the one that can be completely divided
by 1 and the number itself only"

BUT THIS IS A SLIGHTLY WRONG DEFINITION

WHY?
Because 1 is not a prime number and 1 satisfies this condition
1 can be completely divided by 1 and itself
But 1 is NOT prime.


So the definition you should be remembering is:

"A number is prime when it has exactly 2 distinct factors and 
one of the factors is 1 and the other is the number itself"

______________

SOLVING:

BRUTE FORCE:
By brute force approach we can traverse from 1 to n
Then count the number of factors, if they are more than 2
then return false, else true.
TC = O(N)

EFFICIENT APPROACH:

https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems
Here we have seen that to calculate the number of divisors of a number
there is an efficient method which takes O(sqrt(n)) time

We loop from 1 to sqrt(n) to find the total number of factors.
So similarly here also we can use this technique.

*/

int main() {
	// Write your code here

    int n;
    cin>>n;
    int count = 0;

    for(int i=1; i*i<=n; i++){

        if(n%i==0){
            count++;

			if(i != n/i){
				count++;
			}
        }
    }

    if (count == 2) {
        cout << "true";

    } else {
        cout << "false";
    }
}
