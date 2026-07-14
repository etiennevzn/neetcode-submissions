class Solution {
    vector<vector<int>> memo;

    bool dfs(int i, int target, vector<int>& nums){
        if(i == nums.size()) return target == 0;
        if(target < 0) return false;
        if(memo[i][target] != -1) return memo[i][target];

        memo[i][target] = dfs(i+1, target - nums[i], nums) || dfs(i+1, target, nums);
        return memo[i][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        memo.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dfs(0, sum / 2, nums);
    }
};
