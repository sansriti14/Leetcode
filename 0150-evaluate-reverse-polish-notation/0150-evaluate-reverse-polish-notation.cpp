class Solution {
private:
    bool isOperator(string& str) {
        return (str == "+" || str == "-" || str == "*" || str == "/");
    }
    
    int evaluate(int x, int y, string& operation) {
        if(operation == "+") return x + y;
        if(operation == "-") return x - y;
        if(operation == "*") return x * y;
        if(operation == "/") return x / y;
        return 0;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto it: tokens) {
            if(isOperator(it)) {
                int operand2 = stoi(st.top());
                st.pop();
                int operand1 = stoi(st.top());
                st.pop();
                
                string result = to_string(evaluate(operand1, operand2, it));
                st.push(result);
            }
            
            else st.push(it);
        }
        
        return stoi(st.top());
    }
};