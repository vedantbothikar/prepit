#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Array to store stack elements
    int topIndex;  // Index of the top element
    int capacity;  // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];  // Allocate memory for stack
        capacity = size;      // Set the capacity of the stack
        topIndex = -1;        // Initialize top to -1 (stack is empty)
    }

    // Destructor to clean up allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow. Cannot push " << x << endl;
            return;
        }
        arr[++topIndex] = x;  // Increment topIndex and insert element
        cout << x << " pushed onto stack" << endl;
    }

    // Pop the top element from the stack
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow. Cannot pop" << endl;
            return;
        }
        cout << arr[topIndex--] << " popped from stack" << endl;
    }

    // Return the top element of the stack
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;  // Return -1 to indicate the stack is empty
        }
        return arr[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Get the size of the stack
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack stack(5);  // Create a stack of capacity 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Top element is: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element is: " << stack.top() << endl;

    cout << "Stack size is: " << stack.size() << endl;

    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
