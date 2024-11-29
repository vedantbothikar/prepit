#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
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

/*

APPROACH 1:

- Traverse the linkedlist
- convert the int to string
- append the value to a string
- finally reverse the string and check if the reversed string is equal to the original string
- if yes -> palindrome else not


THIS WONT WORK
Because

'321' '1' '321'

This is palindrome
BUT
If we use this approach
then the string would be

'3211321'
WHICH IS NOT PALINDROME

SO THIS APPROACH WOULD FAIL HERE

-------

APPROACH 2:

- keep a pointer called `fast`
- make it jump by 2 places everytime
- this way reach to the last node in the linkedlist
- now keep one pointer at the head of the linked list
- traverse until start < end and keep checking if the elements are equal to each other or not

NOT WORKING
PROBLEM is that we can not do end = end->prev in this
so we cannot go back for checking the prev node

---------------

APPROACH 3:

- store all elements of the linkedlist in an array
- now check if the array is palindrome or not

How to check if the array is palindrome or not?

start = 0
end = n-1

start++
end--

(In array we can go back as well... we can do arr[end--])
So, we can check if an array is palindrome or not....

TC O(N)
SC O(N)


-------------

APPROACH 4:

To solve without any additional space

NOTE:
We can say that any string/linkedlist is palindrome if the
first hald is equal to the reverse of the second half of it

So, now we need to
- reverse the second half of the linkedlist and compare it with
the first half of the linkedlist

BUT
to find the reverse of the second half
you need to find the start of the second half
which means you need to find the middle->next
which means you need to find the middle

- Find the middle of linkedlist
- Reverse the second half reverse(middle->next)
- Compare first and second half of the linkedlist
- Reverse the second half again to bring the linked list back to its original form

NOTE:
Last step is done because we dont want to change the list permanently, so we revert to the original way the list was

TC O(N)
SC O(1)


*/

bool solveArr(LinkedListNode<int> *head)
{

    // base case
    if (head == NULL or head->next == NULL)
    {
        return true;
    }

    // create vector
    vector<int> arr;

    // copy elements from linkedlist to vector
    LinkedListNode<int> *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // check if the array is palindrome

    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {

        if (arr[start] != arr[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

// optimized solution
// without any space usage

// TC O(N)
// SC O(1)

LinkedListNode<int> *findMid(LinkedListNode<int> *head)
{

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // returning middle of the linkedlist
    return slow;
}

LinkedListNode<int> *reverseList(LinkedListNode<int> *head)
{

    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;

    while (curr != NULL)
    {

        next = curr->next;

        // reverse
        curr->next = prev;

        // for next iteration
        prev = curr;
        curr = next;
    }

    return prev;
}

bool solveOpt(LinkedListNode<int> *head)
{

    int ans = true;

    // base case
    if (head == NULL or head->next == NULL)
    {
        return true;
    }

    // find middle of linkedlist
    LinkedListNode<int> *middle = findMid(head);

    // reverse the second half of the linkedlist
    middle->next = reverseList(middle->next);

    // compare the first and second halves

    LinkedListNode<int> *first = head;
    LinkedListNode<int> *second = middle->next;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            ans = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    /*
    NOTE: the below code is not necessary
    but still we dont want to change the original list
    so we are doing this

    */

    // revert back to original
    middle->next = reverseList(middle->next);

    return ans;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.

    return solveOpt(head);
}

int main()
{

    return 0;
}