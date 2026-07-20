class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            for(int j = 0; j < res.size(); ++j){
                if(res[j] != strs[i][j]) res = res.substr(0, j);
            }
        }
        return res;
    }
};