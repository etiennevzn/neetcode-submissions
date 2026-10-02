class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int closeCount = 0;

        for(const char& c : s){
            if(c == ')') closeCount++;
        }

        int openCount = 0;
        string res;
        for(const char& c : s){
            if(c == '('){
                if(openCount == closeCount) continue;
                openCount++;
            }else if(c == ')'){
                closeCount--;
                if(openCount == 0) continue;
                openCount--;
            }
            res.push_back(c);
        }
        
        return res;
    }
};
