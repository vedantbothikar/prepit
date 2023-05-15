#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
/****************************************************************
    https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan


    Following is the Linked List node structure

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

reverse first k nodes

iterate for next k nodes
 join them

*/

Node *reverseList(Node *head, int k)
{

    // base case
    if (head == NULL)
    {
        return head;
    }

    // reverse first k nodes

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while (curr != NULL and count < k)
    {
        next = curr->next;

        // reverse
        curr->next = prev;

        // work for next iteration
        prev = curr;
        curr = next;

        count++;
    }

    // now recurse for reversing other k nodes

    if (curr != NULL)
    {

        // head will be the last node of the newly reversed group of k nodes
        // curr will now be the k+1 th node and we will pass this for the next recursion
        head->next = reverseList(curr, k);
    }

    // prev will be the start of the reversed group of k nodes
    return prev;
}

Node *kReverse(Node *head, int k)
{
    // Write your code here.

    return reverseList(head, k);
}

int main()
{

    return 0;
}