#include <iostream>
#include <stack>
using namespace std;

/*
- https://youtu.be/tqQ5fTamIN4?si=yK91PYUsNWZOzFi0



*/

class Queue {
private:
    stack<int> s1, s2;  // Two stacks to implement the queue

public:
    // Enqueue operation (push)
    void enqueue(int val) {
        s1.push(val);  // Push element to s1
        cout << val << " enqueued to queue" << endl;
    }

    // Dequeue operation (pop)
    void dequeue() {
        if (s2.empty()) {
            // If s2 is empty, transfer all elements from s1 to s2
            if (s1.empty()) {
                cout << "Queue underflow. Cannot dequeue" << endl;
                return;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << s2.top() << " dequeued from queue" << endl;
        s2.pop();  // Pop the top element from s2
    }

    // Front operation (get the front element without removing it)
    int front() {
        if (s2.empty()) {
            // If s2 is empty, transfer all elements from s1 to s2
            if (s1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();  // The front element is now at the top of s2
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    // Get the size of the queue
    int size() {
        return s1.size() + s2.size();  // Total size is the sum of elements in both stacks
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);   // Expected: 10 enqueued to queue
    q.enqueue(20);   // Expected: 20 enqueued to queue
    q.enqueue(30);   // Expected: 30 enqueued to queue
    
    cout << "Front element is: " << q.front() << endl;  // Expected: 10
    
    q.dequeue();     // Expected: 10 dequeued from queue
    q.dequeue();     // Expected: 20 dequeued from queue
    
    cout << "Front element is: " << q.front() << endl;  // Expected: 30
    cout << "Size of the queue: " << q.size() << endl;  // Expected: 1
    
    q.dequeue();     // Expected: 30 dequeued from queue
    q.dequeue();     // Expected: Queue underflow
    
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;  // Expected: Queue is empty
    }
    
    return 0;
}
