class Solution {
private:
    vector<vector<int>> memo;
    int constant;

    int dfs(int i, int target, vector<int>& nums){
        if(i == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        if(target + constant < 0 || target + constant >= memo[0].size()) return 0;
        if(memo[i][target + constant] != -1) return memo[i][target + constant];
        
        memo[i][target + constant] = dfs(i+1, target - nums[i], nums) + dfs(i+1, target + nums[i], nums);
        return memo[i][target + constant];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        constant = accumulate(nums.begin(), nums.end(), 0);
        memo.resize(nums.size(), vector<int>(2 * constant + 1, -1));
        return dfs(0, target, nums);
    }
};
