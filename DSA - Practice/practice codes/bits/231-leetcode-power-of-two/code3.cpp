#include<bits/stdc++.h>
using namespace std;


bool isPowerOfTwo(int n) {

        /*
            this is more efficient than using pow(2,i)
            because we are using the previous value of `val`
            and reducing the computation
        */
        
        int val = 1;
        for(int i=0; i<=30; i++){
            
            
            if(n == val){
                return true;
            }
            
            if(val<=INT_MAX/2)
                val = val*2;
        }

        return false;

    }

int main () {

    int n;
    cin>>n;

    cout<<isPowerOfTwo(n);


    return 0;
}