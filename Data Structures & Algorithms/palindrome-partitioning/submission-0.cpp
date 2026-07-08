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

    void backtrack(int j, int i, vector<string>& cur, string s){
        if(i >= s.size()){
            if(j == s.size()) res.push_back(cur);
            return;
        } 

        if(isPalindrome(s, j, i)){
            cur.push_back(s.substr(j, i-j+1));
            backtrack(i+1, i+1, cur, s);
            cur.pop_back();
        }

        backtrack(j, i+1, cur, s);
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> cur;
        backtrack(0,0,cur,s);
        return res;
    }
};
