#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
/*************************************************
       https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan

        Following is the structure of class Node:

        class Node{
        public:
            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }

        }
**************************************************/

/*

Keep making the data of the nodes as -1
if you find another -1 as the data
Then return true


*/

bool solve(Node *head)
{

    // base case
    if (head == NULL)
    {
        return true;
    }

    Node *curr = head;

    // we just want to detect if the last node is connected back to the head or not
    // if there is an internal loop in the list, we dont care for that
    // which is why we have written the code like this

    while (curr != NULL and curr->data != -1)
    {

        if (curr == head)
        {
            return true;
        }
        curr->data = -1;
        curr = curr->next;
    }

    return false;
}

bool floyd(Node *head)
{

    if (head == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            if (slow == head)
            {
                return true;
            }
            return false;
        }
    }

    return false;
}

bool isCircular(Node *head)
{
    // Write your code here.

    return floyd(head);
}

int main()
{

    return 0;
}