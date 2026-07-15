class Solution {
private:
    int dfs(int i, int target, vector<int>& nums){
        if(i == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        
        return dfs(i+1, target - nums[i], nums) + dfs(i+1, target + nums[i], nums);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, target, nums);
    }
};
