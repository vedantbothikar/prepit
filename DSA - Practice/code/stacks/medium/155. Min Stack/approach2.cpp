/*


Problem Name: 155. Min Stack
Problem Link: https://leetcode.com/problems/min-stack/description/?envType=problem-list-v2&envId=design


Please read:
Explanation: https://gist.github.com/vedantbothikar/934aa4e0ea31cca5420fab4fc7c180eb


Here I am implementing Approach 2
This approach is more optimized in case there are multiple insertions of the min element

*/
class MinStack {

    stack<int> s;
    stack<pair<int, int>> minStack; // {minEle, count}

public:
    MinStack() {
        
    }
    
    void push(int val) {
        /*
            - definitely push to stack
            For minStack:
                - if minStack is empty or minStack top is greater than curr val:
                    - insert the val
                - if the minStack top is equal to val:
                    - increment the counter
                

        */

        // insert in stack
        s.push(val);

        // if minStack is empty or minStack top is greater than curr val
        if(minStack.empty() or minStack.top().first > val) {
            minStack.push({val, 1});
        }
        // if we find the same value as top
        else if (minStack.top().first == val) {
            minStack.top().second++;
        }
        
    }
    
    void pop() {
        /*
        Stack:
            - pop the top
        MinStack:
            - If the stack top is same as the minStack top:
                - decrement counter
                - If counter == 0:
                    - remove the top of MinStack
            - Else:
                - do nothing

        */

        // pop from stack
        int stop = s.top();
        s.pop();

        // if stack top == minStack top
        if(stop == minStack.top().first) {
            
            // decrement counter
            --minStack.top().second;

            // if counter reaches 0
            if(minStack.top().second == 0) {
                minStack.pop();
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top().first;
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