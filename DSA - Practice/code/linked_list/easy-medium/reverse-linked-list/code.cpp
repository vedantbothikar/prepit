#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

/*
https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan

--------------


For iterative

TC O(N)
SC O(1)

--------------

For Recursive

TC O(N)
SC O(N)


*/

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

// solving iteratively
LinkedListNode<int> *solve(LinkedListNode<int> *head)
{

    // base case
    // when no element or when length is 1
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *temp;

    while (curr != NULL)
    {

        temp = curr->next;

        // reverse
        curr->next = prev;

        // prepare for next iteration
        prev = curr;
        curr = temp;
    }

    // last node in original list will now be in prev
    // last node means the first node of the reversed list
    head = prev;

    return head;
}

// recursive solution
LinkedListNode<int> *solveRec(LinkedListNode<int> *curr, LinkedListNode<int> *prev, LinkedListNode<int> *temp)
{

    // base case
    if (curr == NULL)
    {
        return prev;
    }

    temp = curr->next;

    // reverse
    curr->next = prev;

    // prepare for recursion
    prev = curr;
    curr = temp;

    return solveRec(curr, prev, temp);
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here

    // return solve(head);

    // base case
    // when no element or when length is 1
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    return solveRec(head, NULL, head->next);
}

int main()
{

    return 0;
}