class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') open.push(i);
            if(s[i] == '*') star.push(i);
            if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }

        while(!open.empty()){
            if(!star.empty()){
                int openIdx = open.top(), starIdx = star.top();
                open.pop();
                star.pop();
                if(starIdx < openIdx) return false;
            }else{
                return false;
            }
        }

        return true;
    }
};
