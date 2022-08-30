#include<bits/stdc++.h>
using namespace std;

int main() {

// number of times to print the pattern
    int n;
    cin>>n;

    int row=0;

    while(row<n){

        int col=0;

        while(col<n){
            cout<<row+1<<" ";
            col++;
        }

        row++;
        cout<<endl;
    }


    return 0;
}