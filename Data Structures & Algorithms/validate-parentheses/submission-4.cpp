class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char,char> charMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s){
            if(charMap.count(c)){
                if(!charStack.empty() && charStack.top() == charMap[c]){
                    charStack.pop();
                }else{
                    return false;
                }
            }else{
                charStack.push(c);
            }
        }

        return charStack.empty();
    }
};
