class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        if(s.size() % 2 != 0) return false;

        for(size_t i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') charStack.push(s[i]);

            if(s[i] == ')'){
                if(!charStack.empty() && charStack.top() == '('){
                    charStack.pop();
                    continue;
                }else{
                    return false;
                }
            }

            if(s[i] == ']'){
                if(!charStack.empty() && charStack.top() == '['){
                    charStack.pop();
                    continue;
                }else{
                    return false;
                }
            }

            if(s[i] == '}'){
                if(!charStack.empty() && charStack.top() == '{'){
                    charStack.pop();
                    continue;
                }else{
                    return false;
                }
            }
        }

        if(charStack.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};
