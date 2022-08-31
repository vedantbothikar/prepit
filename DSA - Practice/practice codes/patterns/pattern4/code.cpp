#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;

    int row=0;
    while(row<n){
        int col=0;
        while(col<row+1){
            // A
            // cout<<"*"<<" ";
            
            // B
            cout<<row+1<<" ";
            
            col++;

        }
        row++;
        cout<<endl;
    }


    return 0;
}