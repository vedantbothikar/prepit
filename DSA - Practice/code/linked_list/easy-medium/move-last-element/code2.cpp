#include <bits/stdc++.h>
/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

/*

ITERATIVE SOLUTION
*/

LinkedListNode<int> *moveToFront(LinkedListNode<int> *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    LinkedListNode<int> *temp = head;
    LinkedListNode<int> *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = head;
    return temp;
}