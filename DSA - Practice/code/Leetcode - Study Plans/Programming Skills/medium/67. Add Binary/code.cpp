/*
- https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=programming-skills
add function logic:




*/
class Solution {

    void addLogic(int num1, int num2, int& val, int& carry) {

        if(num1 == 1 && num2 == 1) {
            val = 0;
            carry = 1;
            return;
        }
        
        if(num1 == 1 && num2 == 0) {
            val = 1;
            carry = 0;
            return;
        }
        
        if(num1 == 0 && num2 == 0) {
            val = 0;
            carry = 0;
            return;
        }
        
        if(num1 == 0 && num2 == 1) {
            val = 1;
            carry = 0;
            return;
        }

        return;
    }

public:
    string addBinary(string a, string b) {

        string ans = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int l1 = a.size(), l2 = b.size();
        int i1 = 0, i2 = 0;

        int prevCarry = 0;

        while(i1 < l1 or i2 < l2 or prevCarry != 0) {

            // initialization
            int num1 = 0;
            if(i1 < l1) {
                num1 = a[i1] - '0';
            }

            int num2 = 0;
            if(i2 < l2) {
                num2 = b[i2] - '0';
            }

            // addition
            int val;
            int carry;
            int newCarry = 0;

            addLogic(num1, num2, val, carry);
            addLogic(val, prevCarry, val, newCarry);

            if(newCarry != 0) carry = newCarry;
            
            ans += to_string(val);
            prevCarry = carry;

            cout << "#####" << endl;
            cout << "num1, num2: " << num1 << ", " << num2 << endl;
            cout << "val: " << val << endl;
            cout << "carry: " << carry << endl;
            cout << "prevCarry: " << prevCarry << endl;
            cout << "ans: " << ans << endl;

            // updating indices
            if(i1 < l1) i1++;
            if(i2 < l2) i2++;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};