#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin>>n;

    int row=0;
    while(row<n){
        int col = 0;

// A
        // while(col<n-row-1){
        //     cout<<" ";
        //     col++;
        // }

        // col = 0;

        // while(col<row+1){
        //     cout<<"*";
        //     col++;
        // }


// B
        // while(col<row){
        //     cout<<" ";
        //     col++;
        // }

        // col = 0;

        // while(col<n-row){
        //     cout<<row+1+col;
        //     col++;
        // }


// C

        // while(col<n-row-1){
        //     cout<<" ";
        //     col++;
        // }

        // col = 0;

        // while(col<row+1){
        //     cout<<col+1;
        //     col++;
        // }

        // col = 0;

        // while(col<row+1){
        //     if(row-col){
        //         cout<<row-col;
        //     }
            
        //     col++;
        // }


// E 
        col = 0;
        while(col<n-row){
            cout<<col+1<<" ";
            col++;
        }

        col = 0;
        while(col<row){
            cout<<"_"<<" ";
            cout<<"_"<<" ";
            col++;
        }

        col =0;
        while(col<n-row){
            cout<<n-row-col<<" ";
            col++;
        }



        row++;
        cout<<endl;

    }


    return 0;
}