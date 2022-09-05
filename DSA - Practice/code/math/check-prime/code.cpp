#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {

    // keep doing modulus of the number with numbers from 2 to n-1

    for(int i = 2; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;

}

int main () {

    int n;
    cin>>n;

    cout<< isPrime(n);

    return 0;
}