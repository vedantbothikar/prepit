/*

Title: 1290. Convert Binary Number in a Linked List to Integer
Problem Description:
Given head which is a reference node to a singly-linked list. The value of each node in
the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

Problem Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

This solves it in a single traversal of the linked list.

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
        
        ListNode* temp = head; 
        int decVal = 0;
        while(temp) {

            decVal = (decVal * 2) + temp->val;
            temp = temp->next;
        }

        return decVal;
    }
};