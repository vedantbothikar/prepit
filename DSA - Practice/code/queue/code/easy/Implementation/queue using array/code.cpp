
class QueueImpl {
  
    int front = -1, 
        rear = -1,
        capacity, 
        currSize;
    int* arr;
    
    public:
    
        QueueImpl(int reqCapacity) {
            
            arr = new int[reqCapacity];
            capacity = reqCapacity;
            currSize = 0;
        }
        
        ~QueueImpl() {
            delete[] arr;
        }
    
        void push(int num) {
            
            // base cases
            // when queue is full
            // when queue is empty
            
            if(isFull()) {
                cout << "Queue is full" << endl;
                return;
            }
            
            if(isEmpty()) {
                front = rear = 0;
            }
            else {
                rear = (rear+1) % capacity;
            }
            
            arr[rear] = num;
            currSize++;
            
            cout << "Pushed to queue" << endl;
        }
        
        void pop() {
            
            // base cases
            // when queue is empty
            // when there is only 1 element in the queue
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            
            cout << arr[front] << " popped from the queue" << endl;
            
            if(currSize == 1) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % capacity;
            }
            
            currSize--;
        }
        
        int frontInd() {
            
            if(isEmpty()) {
                cout << "Queue empty" << endl;
                return -1;
            }
            
            return arr[front];
        }
        
        int rearInd() {
            
            if(isEmpty()) {
                cout << "Queue empty" << endl;
                return -1;
            }
            
            return arr[rear];
        }
        
        bool isEmpty() {
            
            return currSize == 0;
        }
        
        bool isFull() {
            
            return currSize == capacity;
        }
        
        int getSize() {
            
            return currSize;
        }
    
};


int main() {
    // Write C++ code here
    
    
    QueueImpl q(3);
    
    cout << q.isEmpty() << endl;
    cout << q.getSize() << endl;
    
    q.pop();    // expected empty
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    q.push(4);  // expected overflow
    
    q.pop();
    q.pop();
    
    q.push(5);
    
    q.pop();
    
    q.pop();
    q.pop();    // expected underflow
    
    return 0;
}