#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;

    int row=0;
    int count = 1;
    char letter = 'A';

    while(row<n){
        int col=0;
        while(col<row+1){
            // A
            // cout<<"*"<<" ";
            
            // B
            // cout<<row+1<<" ";

            // C
            // cout<<count<<" ";

            // D
            // cout<<row+1+col<<" ";

            // E
            // cout<<row+1-col<<" ";

            // F
            // cout<<(char)(letter+row)<<" ";

            // G
            // cout<<(char)(letter+count-1)<<" ";

            // H
            // cout<<(char)(letter+row+col)<<" ";

            // I
            // cout<<(char)(letter+n-1-col)<<" ";

            // J
            cout<<(char)(letter +n-1 -row +col)<< " ";
            
            count++;
            col++;

        }

        row++;

        
        // letter = (char) ('A' + ((letter - 'A' + 1) % 26) );


        cout<<endl;
    }


    return 0;
}