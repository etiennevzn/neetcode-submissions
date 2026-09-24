class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int l, int r, const string& s){
        if(l > r) return 0;
        if(l == r) return 1;
        if(memo[l][r] != -1) return memo[l][r];

        int res = 0;
        if(s[l] == s[r]){
            res = 2 + dfs(l + 1, r - 1, s);
        }else{
            res = max(dfs(l + 1, r, s), dfs(l, r - 1, s));
        }

        return memo[l][r] = res;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return dfs(0, n - 1, s);
    }
};