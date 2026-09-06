class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0, mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; --i){
            for(int parity = 0; parity <= 1; ++parity){
                int newParity = (parity + arr[i]) % 2;
                dp[i][parity] = (newParity + dp[i + 1][newParity]) % mod;
            }
            res = (res + dp[i][0]) % mod;
        }

        return res;
    }
};