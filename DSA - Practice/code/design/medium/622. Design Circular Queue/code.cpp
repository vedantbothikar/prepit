/*

- https://leetcode.com/problems/design-circular-queue/description/

initially:
    front = -1
    rear = -1

enqueue:
    rear = (rear + n + 1) % n
    currSize++
Can do this operation if currSize < capacity


dequeue:
    front = (front + n + 1) % n
    currSize--
But if front == rear, then just set both of them to -1 (as initial state)



*/
class MyCircularQueue {

    int *arr;
    int front;
    int rear;
    int currSize;
    int capacity;

public:
    MyCircularQueue(int k) {
        
        front = -1;
        rear = -1;
        currSize = 0;

        arr = new int[k];
        capacity = k;
    }
    
    bool enQueue(int value) {
        
        if(currSize >= capacity) return false;

        if(currSize == 0) {
            front = 0;
        }
        
        int n = capacity;

        rear = (rear + n + 1) % n;
        arr[rear] = value;
        currSize++;

        return true;
    }
    
    bool deQueue() {
        
        if(currSize == 0) return false;

        int n = capacity;

        front = (front + n + 1) % n;
        currSize--;

        if(currSize == 0) {
            front = -1;
            rear = -1;
        }

        return true;
    }
    
    int Front() {
        
        if(currSize == 0) return -1;

        cout << "front: " << front << endl;
        cout << "currSize: " << currSize << endl;

        return arr[front];
    }
    
    int Rear() {
        
        if(currSize == 0) return -1;

        return arr[rear];
    }
    
    bool isEmpty() {
        
        return currSize == 0;
    }
    
    bool isFull() {
        
        return currSize == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */