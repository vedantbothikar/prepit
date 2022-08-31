#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin>>n;

    int row = 0;
    int k = 1;
    while(row<n){
        int col = 0;
        while(col<n){
            cout<<k<<" ";
            col++;
            k++;
        }
        row++;
        cout<<endl;
    }

    return 0;
}