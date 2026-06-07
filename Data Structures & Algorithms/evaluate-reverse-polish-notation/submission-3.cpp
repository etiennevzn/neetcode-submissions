class Solution {
private:
    int operate(int a, int b, string operand){
        if(operand == "+"){
            return a + b;
        }else if(operand == "-"){
            return a - b;
        }else if(operand == "*"){
            return a * b;
        }else if(operand == "/"){
            return a / b;
        }
        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a,b;

        for(size_t i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "+" ||
                tokens[i] == "-"||
                tokens[i] == "*"||
                tokens[i] == "/"){
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(operate(b,a,tokens[i]));
            }else{
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};
