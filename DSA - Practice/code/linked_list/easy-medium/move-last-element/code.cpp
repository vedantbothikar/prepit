#include <bits/stdc++.h>
using namespace std;

// LINKED LIST

/*
https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455?topList=jp-morgan-interview-questions

YOU CAN ALSO SOLVE THE ITERATIVELY


*/

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


Go ahead until next == NULL
now change the next of this node to the start ... which means the head


*/

LinkedListNode<int> *solve(LinkedListNode<int> *head, LinkedListNode<int> *start, LinkedListNode<int> *prev)
{

    // base case
    if (head == NULL)
    {
        return start;
    }

    // if last node
    if (head->next == NULL)
    {
        prev->next = NULL;
        head->next = start;
        return head;
    }
    else
    {
        prev = head;
        head = head->next;
        return solve(head, start, prev);
    }
}

LinkedListNode<int> *moveToFront(LinkedListNode<int> *head)
{

    /*
     Don't write main().
     Don't read input, it is passed as function argument.
     Write your code here.
    */

    // base case
    if (head == NULL)
    {
        return head;
    }

    // if last node
    if (head->next == NULL)
    {
        return head;
    }

    return solve(head, head, head);
}

int main()
{

    return 0;
}