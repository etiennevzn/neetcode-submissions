class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, int j, string& s, string& t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int res = dfs(i+1, j, s, t);
        if(s[i] == t[j]) res += dfs(i+1, j+1, s, t);
        memo[i][j] = res;
        return res;
    }
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) return 0;
        memo.resize(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t);
    }
};
