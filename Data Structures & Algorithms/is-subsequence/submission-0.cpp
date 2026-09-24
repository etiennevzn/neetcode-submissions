class Solution {
private:
    vector<vector<int>> memo;
    bool dfs(int i, int j, const string& s, const string& t){
        if(i == s.size()) return true;
        if(j == t.size()) return false;
        if(memo[i][j] != -1) return memo[i][j];

        if(s[i] == t[j]) return memo[i][j] = dfs(i + 1, j + 1, s, t);
        return memo[i][j] = dfs(i, j + 1, s, t);
    }
public:
    bool isSubsequence(string s, string t) {
        memo.resize(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t);
    }
};