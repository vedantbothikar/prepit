/*

This is a longer approach to solve the problem. (Using string to store the binary number)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*

parse the linkedlist
append the values to a string 

now traverse the characters in the string and calculate the value

*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        string numstr = "";

        ListNode* temp = head; 
        // traverse the linked list
        while(temp) {

            numstr = to_string(temp->val) + numstr;
            temp = temp->next;
        }

        int decVal = 0;
        int power = 0;
        // traverse the numstr can calculate the decimal val
        for(char ch : numstr) {

            int digit = ch - '0';
            decVal += (digit * pow(2, power));
            power++;
        }

        return decVal;
    }
};