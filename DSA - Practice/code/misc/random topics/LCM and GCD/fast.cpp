/*

This is a faster way - where you will not get time limit exceeded error

*/


class Solution {
  public:
  
    // helper function to get gcd of two numbers.
    long long gcd(long long a , long long b)
    {
        if(a == 0)
            return b;
        return gcd(b%a, a);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        
        vector<long long> arr(2);
        
        long long g = gcd(A,B);   // gcd of two numbers.
        long long l = (A*B)/g;    // product of 2 numbers divided by their gcd gives their lcm.
        
        arr[0] = l;
        arr[1] = g;
        
        return arr;
    }
};