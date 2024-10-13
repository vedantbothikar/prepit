#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {}
};

class Stack {
private:
    Node* topNode;  // Pointer to the top of the stack
    int currSize;   // Current size of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        topNode = NULL;  // Initially, the stack is empty
        currSize = 0;
    }

    // Push operation (insert element at the top)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;  // Link the new node with the current top
        topNode = newNode;        // Make the new node the top node
        currSize++;
        cout << val << " pushed to stack" << endl;
    }

    // Pop operation (remove the top element)
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop" << endl;
            return;
        }
        Node* temp = topNode;  // Store the current top node
        cout << topNode->data << " popped from stack" << endl;
        topNode = topNode->next;  // Move the top pointer to the next node
        delete temp;              // Delete the old top node
        currSize--;
    }

    // Top operation (get the top element without removing it)
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == NULL;
    }

    // Get the size of the stack
    int size() {
        return currSize;
    }
};

int main() {
    Stack s;
    
    s.push(10);   // Expected: 10 pushed to stack
    s.push(20);   // Expected: 20 pushed to stack
    s.push(30);   // Expected: 30 pushed to stack
    
    cout << "Top element is: " << s.top() << endl;  // Expected: 30
    
    s.pop();     // Expected: 30 popped from stack
    s.pop();     // Expected: 20 popped from stack
    
    cout << "Top element is: " << s.top() << endl;  // Expected: 10
    
    cout << "Size of the stack: " << s.size() << endl;  // Expected: 1
    
    s.pop();     // Expected: 10 popped from stack
    s.pop();     // Expected: Stack underflow
    
    if (s.isEmpty()) {
        cout << "Stack is empty" << endl;  // Expected: Stack is empty
    }
    
    return 0;
}
