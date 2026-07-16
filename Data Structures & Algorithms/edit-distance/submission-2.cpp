class Solution {
    vector<vector<int>> memo;

    int dfs(int i, int j, const string& word1, const string& word2){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]){
            memo[i][j] = dfs(i+1, j+1, word1, word2);
        }else{
            memo[i][j] = 1 + min(dfs(i, j+1, word1, word2), min(dfs(i+1, j, word1, word2), dfs(i+1, j+1, word1, word2)));
        }

        return memo[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        memo.resize(word1.size(), vector<int>(word2.size(), -1));
        return dfs(0, 0, word1, word2);
    }
};
