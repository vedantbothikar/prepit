/*

I have solved without heap, but you can use maxheap for simplicity

- https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/


To get the largest number, I will have to find the descending order of both odd and even digits
and put them them in the places where odd and even digits were already there.

How to get all digits?
- Dividing the number by 10 until it is 0

How to understand the positions of even or odd digits?
- While dividing, you will understand that 

Where to store the positons and the numbers?
vector<int> odd // stores the odd digits (later we can sort them)
vector<int> even
vector<int> pos
    - pos will be 1 if digit at that position is even
    - pos will be 0 if digit at that position is odd

snum = to_string(num)
for(i to length of snum) {

    char ch = s[i]
    string tempch = ch
    int digit = stoi(tempch)

    // even digit
    if(digit % 2 == 0) {
        even.push_back(digit)
        pos.push_back(1)
    }
    else {
        odd.push_back(digit)
        pos.push_back(0)
    }
}

sort(odd)
sort(even)

string sans = ""
int evenInd = 0
int oddInd = 0
for(i = 0 to len of pos) {

    if(pos[i] == 1) {
        s += even[evenInd];
        evenInd++;
    }
    else {
        s += odd[oddInd]
        oddInd++
    }
}

int ans = stoi(sans)
return ans

TC: O(nlogn)
SC: O(n)

*/
class Solution {
public:
    int largestInteger(int num) {

        vector<char> odd;
        vector<char> even;
        vector<int> pos;

        string snum = to_string(num);
        for(char ch : snum) {

            int digit = ch - '0';

            // even
            if(digit % 2 == 0) {
                even.push_back(ch);
                pos.push_back(1);
            }
            else {
                odd.push_back(ch);
                pos.push_back(0);
            }
        }
        
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        string sans = "";
        int evenInd = 0, oddInd = 0;
        for(int x : pos) {

            // even
            if(x == 1) {
                sans += even[evenInd];
                evenInd++;
            }
            else {
                sans += odd[oddInd];
                oddInd++;
            }
        }
        
        int ans = stoi(sans);
        return ans;
    }
};