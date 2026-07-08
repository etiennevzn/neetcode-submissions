class Solution {
private:
    vector<string> res;

    void backtrack(string& cur, int openLeft, int closeLeft, int n){
        if(!openLeft && !closeLeft){
            res.push_back(cur);
            return;
        }
        
        if(closeLeft == openLeft){
            cur.push_back('(');
            backtrack(cur, openLeft-1, closeLeft, n);
            cur.pop_back();
        }else if(closeLeft > openLeft){
            if(openLeft){
                cur.push_back('(');
                backtrack(cur, openLeft-1, closeLeft, n);
                cur.pop_back();
            }

            cur.push_back(')');
            backtrack(cur, openLeft, closeLeft-1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        string cur = "";
        backtrack(cur, n, n, n);
        return res;
    }
};
