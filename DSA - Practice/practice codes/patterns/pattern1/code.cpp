#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin>>n;

    int row = 0;
    char letter = 'A';
    int k = 0;
    int k2 = 1;

    while(row<n){
        int col=0;

        while (col<n)
        {

            // a
            // cout<<k2<<" ";

            // b
            // cout<<row+1<<" ";

            // A
            // cout<<col+1<<" ";

            // B
            // cout<<n-col<<" ";

            // C
            // cout<<letter<<" ";

            // D
            // cout<<(char)(letter+col)<<" ";

            // E
            // cout<<(char)(letter+k);

            // F
            // cout<<(char)(letter+row+col)<<" ";

            col++;
            k++;
            k2++;
        }

        row++;
        
        // C
        // letter = (char)('A' + ((letter - 'A' + 1))%26);
        
        
        cout<<endl;
    }


    return 0;
}