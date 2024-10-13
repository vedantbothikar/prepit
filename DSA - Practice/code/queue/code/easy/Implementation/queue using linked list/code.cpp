#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {}  // Constructor to initialize a node
};

class Queue {
private:
    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue
    int currSize;     // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        frontNode = rearNode = NULL;  // Initially, the queue is empty
        currSize = 0;
    }

    // Enqueue operation (insert element at the rear)
    void enqueue(int val) {
        Node* newNode = new Node(val);  // Create a new node
        if (isEmpty()) {
            frontNode = rearNode = newNode;  // If the queue is empty, both front and rear point to the new node
        } else {
            rearNode->next = newNode;  // Link the new node to the end of the queue
            rearNode = newNode;        // Update the rear pointer to the new node
        }
        currSize++;
        cout << val << " enqueued to queue" << endl;
    }

    // Dequeue operation (remove the front element)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow. Cannot dequeue" << endl;
            return;
        }
        Node* temp = frontNode;        // Store the current front node
        cout << frontNode->data << " dequeued from queue" << endl;
        frontNode = frontNode->next;   // Move the front pointer to the next node
        delete temp;                   // Delete the old front node
        currSize--;
        
        if (isEmpty()) {  // If the queue is now empty, reset rearNode to NULL
            rearNode = NULL;
        }
    }

    // Get the front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return frontNode->data;
    }

    // Get the rear element
    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rearNode->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Get the size of the queue
    int size() {
        return currSize;
    }
};

int main() {
    Queue q;

    q.enqueue(10);  // Expected: 10 enqueued to queue
    q.enqueue(20);  // Expected: 20 enqueued to queue
    q.enqueue(30);  // Expected: 30 enqueued to queue
    
    cout << "Front element is: " << q.front() << endl;  // Expected: 10
    cout << "Rear element is: " << q.rear() << endl;    // Expected: 30

    q.dequeue();  // Expected: 10 dequeued from queue
    q.dequeue();  // Expected: 20 dequeued from queue
    
    cout << "Front element is: " << q.front() << endl;  // Expected: 30
    cout << "Size of the queue: " << q.size() << endl;  // Expected: 1

    q.dequeue();  // Expected: 30 dequeued from queue
    q.dequeue();  // Expected: Queue underflow
    
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;  // Expected: Queue is empty
    }

    return 0;
}
