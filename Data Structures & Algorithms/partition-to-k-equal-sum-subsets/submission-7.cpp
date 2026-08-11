class Solution {
private:
    int target;
    vector<int> memo;

    int dfs(int curSum, int mask, int k, int start, const vector<int>& nums){
        if(k == 0) return 1;
        if(curSum == target) return memo[mask] = dfs(0, mask, k - 1, 0, nums);

        for(int j = start; j < nums.size(); ++j){
            if(mask & (1 << j) || curSum + nums[j] > target) continue;
            if(dfs(curSum + nums[j], mask | (1 << j), k, j + 1, nums)) return true;
            if(curSum == 0) return memo[mask] = 0;
        }

        return memo[mask] = 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        target = sum / k;
        sort(nums.rbegin(), nums.rend());
        memo.resize(1 << nums.size(), -1);
        return dfs(0, 0, k, 0, nums);
    }
};