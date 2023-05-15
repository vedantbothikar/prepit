#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

       class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

/*

basic approach can be that:
- traverse whole list
- calculate the length of the list
- again traverse the list, now stop when you reach the half of the length of the list


Better approach:
2 pointer technique:
- single, double
single will hop to next node
double will hop to next of next node

when head->next == NULL
it means there are odd number of elements
print the single value => it is the middle element

when head->next->next == NULL
it means that there are even number of elements
print single->next => it is the middle element


*/

Node *solve(Node *head)
{

    // base case
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *singleHop = head;
    Node *doubleHop = head;

    while (doubleHop->next != NULL and doubleHop->next->next != NULL)
    {
        singleHop = singleHop->next;
        doubleHop = doubleHop->next->next;
    }

    // odd nodes
    if (doubleHop->next == NULL)
    {
        return singleHop;
    }
    else if (doubleHop->next->next == NULL)
    {
        return singleHop->next;
    }
}

Node *findMiddle(Node *head)
{
    // Write your code here

    return solve(head);
}

int main()
{

    return 0;
}