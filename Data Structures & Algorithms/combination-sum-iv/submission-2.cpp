class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;

        for(int i = 1; i <= target; ++i){
            int res = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(i - nums[j] >= 0) res += dp[i - nums[j]];
            }
            dp[i] = res;
        }
        return dp[target];
    }
};