#include<bits/stdc++.h>
using namespace std;


    bool isPowerOfTwo(int n) {
        
        // corner case
        if(n == 0){
            return false;
        }
        
        int count = 0;
        while(n!=0){
            
            if(count>1){
                return false;
            }
            
            
            if(n&1){
                count++;
            }
            
            n = n>>1;
        }
        
        if(count>1){
            return false;
        }
        
        return true;
        
    }

int main () {

    int n;
    cin>>n;

    cout<<isPowerOfTwo(n);


    return 0;
}