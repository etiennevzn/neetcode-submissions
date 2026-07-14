class Solution {
    bool dfs(int i, int cur, int target, vector<int>& nums){
        if(cur == target) return true;
        if(i == nums.size() || cur > target) return false;

        return dfs(i+1, cur + nums[i], target, nums) || dfs(i+1, cur, target, nums);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        return dfs(0, 0, sum / 2, nums);
    }
};
