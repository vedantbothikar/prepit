/*

BETTER APPROACH:
In this approach, we will check till square root of n

Watch the video from here:
https://youtu.be/1xNbjMdbjug?si=kvRb4gHxxG8aje2C&t=1812

So suppose the number is 16

1 x 16
2 x 8 
4 x 4   # After this numbers repeat
8 x 2
16 x 1

So there are 2 sections, so instead of looping from 1 to n
We can loop from 1 to sqrt of n


So we loop till sqrt of n because after that the divisors repeat

The divisors will be i and n/i
For example, if i = 2, then n/i = 16/2 = 8

CASE:
There can be case where 6x6=36
So the divisor can repeat here, so we will have to check this


*/


int* printDivisors(int n, int &size){
// Write your code here

    int *arr = new int[n];
    size = 0;
    int loopSize = sqrt(n);


    for(int i=1; i <= loopSize; i++){

      if (n % i == 0) {

        arr[size] = i;
        size++;

        // add n/i to the list only if i is NOT EQUAL to n/i
        if(i != n/i){
          arr[size] = n/i;
          size++;
        }
      }
    }

    sort(arr, arr + size);
    return arr;
}
