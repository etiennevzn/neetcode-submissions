class Solution {
private:
    vector<int> memo;
    int dfs(int i, const vector<int>& nums){
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int rob = nums[i] + dfs(i + 2, nums);
        int skip = dfs(i + 1, nums);
        return memo[i] = max(rob, skip);
    }
public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(0, nums);
    }
};
