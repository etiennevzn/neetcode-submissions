class Solution {
private:
    vector<vector<int>> memo;
    bool dfs(int i, int j, const string& s, const string& p){
        if(i == s.size() && j == p.size()) return true;
        if(memo[i][j] != - 1) return memo[i][j];

        if(i == s.size()){
            if(j + 1 < p.size() && p[j + 1] == '*'){
                memo[i][j] = dfs(i, j + 2, s, p);
                return memo[i][j];
            }
            return false;
        }

        bool res = false;

        if(s[i] == p[j] || p[j] == '.'){
            if(j + 1 < p.size() && p[j + 1] == '*'){
                res = dfs(i, j + 2, s, p) || dfs(i + 1, j + 2, s, p) || dfs(i + 1, j, s, p);
            }else{
                res = dfs(i + 1, j + 1, s, p);
            }
        }else{
            if(j + 1 < p.size() && p[j + 1] == '*') res = dfs(i, j + 2, s, p);
        }

        memo[i][j] = res;
        return res;
    }
public:
    bool isMatch(string s, string p) {
        memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p);
    }
};
