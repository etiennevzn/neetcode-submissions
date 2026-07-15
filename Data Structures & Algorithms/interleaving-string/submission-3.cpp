class Solution {
private:
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3){
        if(k == s3.size()) return true;
        
        bool take1 = false;
        bool take2 = false;

        if(i < s1.size() && s1[i] == s3[k]){
            if(dfs(i+1, j, k+1, s1, s2, s3)) take1 = true;
        }

        if(j < s2.size() && s2[j] == s3[k]){
            if(dfs(i, j+1, k+1, s1, s2, s3)) take2 = true;
        }

        return take1 || take2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {   
        if(s1.size() + s2.size() != s3.size()) return false;
        return dfs(0,0,0,s1,s2,s3);
    }
};
