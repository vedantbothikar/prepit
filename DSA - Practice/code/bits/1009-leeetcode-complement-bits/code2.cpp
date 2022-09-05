#include<bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n) {
        
        int mask = 0;
        int n2 = n;
        
        // corner case
        if(n == 0){
            return 1;
        }
           
        while(n!=0){        
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