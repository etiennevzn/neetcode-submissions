class Solution {
private:
    vector<int> memo;

    int dfs(int target, vector<int>& nums){
        if(target == 0) return 1;
        if(memo[target] != -1) return memo[target];
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(target - nums[i] >= 0) res += dfs(target - nums[i], nums);
        }
        return memo[target] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target + 1, -1);
        return dfs(target, nums);
    }
};