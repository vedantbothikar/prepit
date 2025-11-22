/*

Problem Name: 155. Min Stack
Problem Link: https://leetcode.com/problems/min-stack/description/?envType=problem-list-v2&envId=design


- https://leetcode.com/problems/min-stack/description/
Maintain another stack called minStack that holds the minimum element at the current position of the curernt element element at the original stack.

Please read:
Explanation: https://gist.github.com/vedantbothikar/934aa4e0ea31cca5420fab4fc7c180eb



Watch: https://youtu.be/qkLl7nAwDPo

*/
class MinStack {
public:

    stack<int> s;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {

        s.push(val);
        
        if(minStack.empty()) {
            minStack.push(val);
        }
        else {
            int num = min(minStack.top(), val);
            minStack.push(num);
        }
    }
    
    void pop() {
        
        s.pop();
        minStack.pop();
    }
    
    int top() {
        
        return s.top();
    }
    
    int getMin() {
        
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */