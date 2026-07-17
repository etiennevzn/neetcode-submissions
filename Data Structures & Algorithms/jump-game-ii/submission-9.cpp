class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        vector<int> dp(n, 0);
        for(int i = n - 2; i >= 0; --i){
            int res = nums.size();
            for(int j = 1; j <= nums[i]; ++j){
                if(i + j < nums.size()) res = min(res, 1 + dp[i + j]);
            }
            dp[i] = res;
        }

        return dp[0];
    }
};
