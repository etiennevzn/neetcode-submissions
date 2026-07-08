class Solution {
private:
    vector<vector<string>> res;

    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            r--;
            l++;
        }
        return true;
    }

    void backtrack(int i, vector<string>& cur, string s){
        if(i >= s.size()){
            res.push_back(cur);
            return;
        } 

        for(int j = i; j < s.size(); ++j){
            if(isPalindrome(s, i, j)){
                cur.push_back(s.substr(i, j-i+1));
                backtrack(j+1, cur, s);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> cur;
        backtrack(0,cur,s);
        return res;
    }
};
