#include <bits/stdc++.h> 

/*

# APPROACH
- We will have to dissect each digit from the number
- For every digit find the power
- We can use the pow function to find the power of the digit
- Add every value and check the sum after the loop


*/

int countDigits(int num) {

    if(num == 0) {
        return 1;
    }
    if(num < 0) {
        num = -num;
    }

    return floor(log10(num) + 1);
}


bool isArmstrong(int num) {
    // Write your code here

    int totalDigits = countDigits(num);
    int ogNum = num;
    int sum = 0;
    while(num != 0){

        int digit = num % 10;

        sum += pow(digit, totalDigits);

        num = num / 10;
    }

    return sum == ogNum;
}



