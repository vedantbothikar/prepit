#include<bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n) {
        
        int mask = 0;
        
        // we are keeping a copy of n so that we can use the untampered one 
        //later on
        int n2 = n;
        
        if(n == 0){
            return 1;
        }
        
        
        while(n!=0){
            
            // we are adding 1 to the mask as many times as there are relevant
            // bits in `n`  
           
            mask = mask<<1;
            mask = mask | 1;
            
            
            n = n>>1;
        }
        
        
        int ans = (~n2) & mask;
        
        
       return ans;
}


int main () {

    int n;
    cin>>n;


    cout<<bitwiseComplement(n);


    return 0;
}