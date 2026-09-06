class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, int parity, vector<int>& arr){
        if(i == arr.size()) return 0;
        if(memo[i][parity] != -1) return memo[i][parity];

        int newParity = (parity + arr[i]) % 2;
        int res = newParity + dfs(i + 1, newParity, arr);
        return memo[i][parity] = res;
    }
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        memo.resize(n, vector<int>(2, -1));
        
        for(int i = 0; i < n; ++i){
            res += dfs(i, 0, arr);
        }

        int mod = 1000000007;
        return res % mod;
    }
};