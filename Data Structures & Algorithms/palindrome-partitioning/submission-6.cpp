class Solution {
private:
    vector<vector<string>> res;

    bool isPalindrome(const string& cur){
        if(cur.empty()) return false;

        int l = 0, r = cur.size() - 1;

        while(l < r){
            if(cur[l] != cur[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void dfs(int i, vector<string>& curArr, string& cur, const string& s){
        if(i == s.size()){
            if(isPalindrome(cur)){
                curArr.push_back(cur);
                res.push_back(curArr);
                curArr.pop_back();
            }
            return;
        }

        if(isPalindrome(cur)){
            curArr.push_back(cur);
            string oldCur = cur;
            cur = s[i];
            dfs(i + 1, curArr, cur, s);
            curArr.pop_back();
            cur = oldCur;
        }

        cur += s[i];
        dfs(i + 1, curArr, cur, s);
        cur.pop_back();
    }
public:
    vector<vector<string>> partition(string s) {
        string cur;
        vector<string> curArr;
        dfs(0, curArr, cur, s);
        return res;
    }
};
