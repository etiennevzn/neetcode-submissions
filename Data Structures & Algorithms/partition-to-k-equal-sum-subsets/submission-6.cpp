class Solution {
private:
    int target;
    bool dfs(int curSum, int mask, int k, int start, const vector<int>& nums){
        if(k == 0) return true;
        if(curSum == target) return dfs(0, mask, k - 1, 0, nums);

        for(int j = start; j < nums.size(); ++j){
            if(mask & (1 << j) || curSum + nums[j] > target) continue;
            if(dfs(curSum + nums[j], mask | (1 << j), k, j + 1, nums)) return true;
            if(curSum == 0) return false;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        target = sum / k;
        sort(nums.rbegin(), nums.rend());
        return dfs(0, 0, k, 0, nums);
    }
};