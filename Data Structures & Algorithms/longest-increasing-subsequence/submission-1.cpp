class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size()-1] = 1;
        int res = 1;
        for(int i = nums.size()-2; i >= 0; --i){
            dp[i] = 1;
            for(int j = i+1; j < nums.size(); ++j){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
