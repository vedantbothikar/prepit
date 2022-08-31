#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin>>n;

    int row = 0;

    while(row<n){
        int col=0;
        while (col<n)
        {
            cout<<col+1<<" ";
            col += 1;
        }
        row += 1;
        cout<<endl;
    }


    return 0;
}