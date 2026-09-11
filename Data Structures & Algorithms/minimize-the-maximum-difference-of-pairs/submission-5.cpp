class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
        for(int i = 1; i <= p; ++i){
            dp[n - 1][i] = INT_MAX;
            dp[n][i] = INT_MAX;
        }

        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; --i){
            for(int j = 1; j <= p; ++j){
                int take = max(nums[i + 1] - nums[i], dp[i + 2][j - 1]);
                int skip = dp[i + 1][j];
                dp[i][j] = min(take, skip);
            }
        }
        return dp[0][p];
    }
};