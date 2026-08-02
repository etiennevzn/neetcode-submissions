class Solution {
public:
    string decodeString(string s) {
        vector<string> stringStack;
        stack<int> countStack;
        string cur = "";
        int k = 0;

        for(const char& c : s){
            if(isdigit(c)){
                k = k * 10 + (c - '0');
            }else if(c == '['){
                stringStack.push_back(cur);
                countStack.push(k);
                cur = "";
                k = 0;
            }else if(c == ']'){
                string tmp = cur;
                cur = stringStack.back();
                stringStack.pop_back();
                int count = countStack.top();
                countStack.pop();
                
                for(int i = 0; i < count; ++i){
                    cur += tmp;
                }
            }else{
                cur += c;
            }
        }

        return cur;
    }
};