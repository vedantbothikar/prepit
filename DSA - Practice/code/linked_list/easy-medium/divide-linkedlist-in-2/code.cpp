#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/divide-linked-list-in-two_763646?topList=jp-morgan-interview-questions
*/

#include <bits/stdc++.h>
/************************************************************

    Following is the list node structure:

    template <typename T>
    class Node {
        public:
            T data;
            Node* next;

            Node(T data) {
                next = NULL;
                this->data = data;
            }
            ~Node() {
                if (next != NULL) {
                    delete next;
                }
            }
    };

************************************************************/

void solve(Node<int> *head, Node<int> **first, Node<int> **second)
{

    // base cases
    if (head == NULL)
    {
        *first = NULL;
        *second = NULL;
        return;
    }

    if (head->next == NULL)
    {
        *first = head;
        *second = NULL;
        return;
    }

    *first = head;
    *second = head->next;

    Node<int> *tempfirst = *first;
    Node<int> *tempsecond = *second;

    // start from 3rd value
    head = head->next->next;
    int count = 3;

    while (head != NULL)
    {

        // odd
        if (count & 1)
        {
            tempfirst->next = head;
            tempfirst = tempfirst->next;
        }
        else
        {
            tempsecond->next = head;
            tempsecond = tempsecond->next;
        }

        head = head->next;
        count++;
    }

    tempfirst->next = NULL;
    tempsecond->next = NULL;
}

pair<Node<int> *, Node<int> *> divideList(Node<int> *head)
{
    // Write your code here.
    Node<int> *first;
    Node<int> *second;

    solve(head, &first, &second);

    pair<Node<int> *, Node<int> *> ans = make_pair(first, second);

    return ans;
}

int main()
{

    return 0;
}