class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(int i, int j, string& s1, string& s2, string& s3){
        if(i + j == s3.size()) return true;
        if(memo[i][j] != -1) return memo[i][j];

        int k = i + j;
        memo[i][j] = 0;
        if(i < s1.size() && s1[i] == s3[k]){
            if(dfs(i+1, j, s1, s2, s3)) memo[i][j] = 1;
        }

        if(j < s2.size() && s2[j] == s3[k]){
            if(dfs(i, j+1, s1, s2, s3)) memo[i][j] = 1;
        }

        return memo[i][j];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {   
        if(s1.size() + s2.size() != s3.size()) return false;
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(0,0,s1,s2,s3);
    }
};
