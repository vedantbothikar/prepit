#include <iostream>
#include <queue>
using namespace std;

/*

- https://youtu.be/tqQ5fTamIN4?si=QCKuacLq-riDlOtL
*/

class Stack {
private:
    queue<int> q;   // Single queue to implement the stack
    int currSize;   // Keep track of the current size of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        currSize = 0;
    }

    // Push operation
    void push(int val) {
        currSize++;  // Increment size of the stack

        // Add the new element to the queue
        q.push(val);

        // Rotate the queue to move the new element to the front
        for (int i = 0; i < currSize - 1; i++) {
            // Move the front element to the back
            q.push(q.front());
            q.pop();
        }

        cout << val << " pushed to stack" << endl;
    }

    // Pop operation
    void pop() {
        if (q.empty()) {
            cout << "Stack underflow. Cannot pop" << endl;
            return;
        }

        cout << q.front() << " popped from stack" << endl;
        q.pop();  // Remove the front element
        currSize--;  // Decrease size
    }

    // Top operation (get the top element without removing it)
    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();  // Front of q is the top of the stack
    }

    // Check if the stack is empty
    bool isEmpty() {
        return currSize == 0;
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
