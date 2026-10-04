class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int j, const string& text1, const string& text2){
        if(i == text1.size() || j == text2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j]) return memo[i][j] = 1 + dfs(i + 1, j + 1, text1, text2);
        return memo[i][j] = max(dfs(i + 1, j, text1, text2), dfs(i, j + 1, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0, text1, text2);
    }
};
