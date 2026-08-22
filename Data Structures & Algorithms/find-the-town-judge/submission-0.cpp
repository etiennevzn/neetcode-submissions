class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> numTrusted(n + 1, 0);
        vector<int> numTrust(n + 1, 0);
        
        for(const auto& t : trust){
            numTrusted[t[0]]++;
            numTrust[t[1]]++;
        }

        for(int i = 1; i <= n; ++i){
            if(!numTrusted[i] && numTrust[i] == n - 1) return i;
        }

        return -1;
    }
};