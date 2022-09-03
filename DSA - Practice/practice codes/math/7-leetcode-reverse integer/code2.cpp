#include<bits/stdc++.h>
using namespace std;

// BETTER SOLUTION

// if condition:
// to check if ans is in range or not
// we are dividing by 10 because 
// later we are going to multiply `ans` by 10 

int reverse(int x) {
        
        int ans  = 0;
        while( x != 0) {
            
            int digit = x % 10;
            cout<<"digit:"<<digit<<endl;

            if( (ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }
            
            // dry run this formula and you will understand it
            ans = (ans * 10) + digit;
            x = x / 10;
            
        }
        return ans;
     
        
        
    }


int main () {



        
        int n;
        cin>>n;
        cout<<reverse(n);

    return 0;
}