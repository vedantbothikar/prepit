#include<bits/stdc++.h>
using namespace std;


    bool isPowerOfTwo(int n) {

        for(int i=0; i<=30; i++){
            
            int val = pow(2,i);
            if(n == val){
                return true;
            }
        }

        return false;

    }

int main () {

    int n;
    cin>>n;

    cout<<isPowerOfTwo(n);


    return 0;
}