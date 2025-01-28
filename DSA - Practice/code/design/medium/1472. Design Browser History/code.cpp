/*


- https://leetcode.com/problems/design-browser-history/?envType=study-plan-v2&envId=programming-skills
- https://youtu.be/mG3KLugbOdc?si=5fAZeU79utvdAebD


2 stacks
1. back
2. forward


## VISIT
- backStack.push(currURL)
- currURL = newURL
- forwardStack => empty it

## BACK
- pop the stack urls steps no of time and while doing so, push the urls to forwardStack
- 

## FORWARD
- push the currentURL to backStack
- pop the forward stack steps no of times



*/
class BrowserHistory {

    string currURL;
    stack<string> backStck;
    stack<string> forwardStck;

public:
    BrowserHistory(string homepage) {
        
        currURL = homepage;

        stack<string> emptyStack;
        backStck.swap(emptyStack);
        forwardStck.swap(emptyStack);
    }
    
    void visit(string url) {
        
        backStck.push(currURL);
        currURL = url;

        stack<string> emptyStack;
        forwardStck.swap(emptyStack);
    }
    
    string back(int steps) {
        
        while(steps && !backStck.empty()) {

            forwardStck.push(currURL);
            
            string backTop = backStck.top();
            currURL = backTop;
            
            backStck.pop();

            steps--;
        }

        return currURL;
    }
    
    string forward(int steps) {
        
        while(steps && !forwardStck.empty()) {

            backStck.push(currURL);
            
            string forwardTop = forwardStck.top();
            currURL = forwardTop;
            forwardStck.pop();

            steps--;
        }

        return currURL;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */