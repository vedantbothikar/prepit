/*

- https://leetcode.com/problems/design-linked-list/

Maintain
- head ptr
- tail ptr
- currSize 





*/
class Node
{

public:
    int val;
    Node *next;
    Node *prev;

    Node()
    {
        this->val = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyLinkedList
{

    Node *head;
    Node *tail;
    int llSize;

public:
    MyLinkedList()
    {
        // create the head and tail ptr
        this->head = new Node();
        this->tail = new Node();

        head->next = tail;
        tail->prev = head;

        llSize = 0;
    }

    int get(int index)
    {

        if (index < 0 or index >= llSize)
            return -1;

        Node *temp = head;
        temp = temp->next;

        while (index)
        {

            temp = temp->next;

            index--;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {

        Node *newNode = new Node(val);
        Node *firstNode = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = firstNode;
        firstNode->prev = newNode;

        llSize++;
    }

    void addAtTail(int val)
    {

        Node *newNode = new Node(val);
        Node *lastNode = tail->prev;

        newNode->next = tail;
        newNode->prev = lastNode;

        lastNode->next = newNode;
        tail->prev = newNode;

        llSize++;
    }

    void addAtIndex(int index, int val)
    {
        // insert node before the index th node

        if (index < 0 or index > llSize)
            return;

        Node *prevIndNode = head;
        Node *indNode = head->next;

        // reach to the indNode
        while (index)
        {

            prevIndNode = indNode;
            indNode = indNode->next;
            index--;
        }

        // add the newNode
        Node *newNode = new Node(val);

        newNode->prev = prevIndNode;
        newNode->next = indNode;

        prevIndNode->next = newNode;
        indNode->prev = newNode;

        llSize++;
    }

    void deleteAtIndex(int index)
    {

        if (index < 0 or index >= llSize)
            return;

        Node *prevIndNode = head;
        Node *indNode = head->next;
        // goto index node
        while (index)
        {

            prevIndNode = indNode;
            indNode = indNode->next;
            index--;
        }

        // delete indNode;
        prevIndNode->next = indNode->next;

        Node *nextIndNode = indNode->next;
        nextIndNode->prev = prevIndNode;

        delete indNode;

        llSize--;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */