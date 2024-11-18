class Solution {

    bool isOperator(string s) {

        if(s == "+" or s == "-" or s == "*" or s == "/") {
            return true;
        }

        return false;
    }

    int applyOperation(int first, int second, string operation) {

        if(operation == "+") return second + first;
        else if(operation == "-") return second - first;
        else if(operation == "*") return second * first;
        else if(operation == "/") return second / first;

        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;

        for(string token : tokens) {

            if(isOperator(token)) {

                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();

                int ans = applyOperation(first, second, token);

                s.push(ans);
            }
            else {
                
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};