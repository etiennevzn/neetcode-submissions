class Solution {
private:
    int target;
    bool dfs(int curSum, int mask, int k, const vector<int>& nums){
        if(k == 0) return true;

        for(int j = 0; j < nums.size(); ++j){
            if(mask & (1 << j)) continue;
            mask |= (1 << j);
            if(curSum + nums[j] == target){
                if(dfs(0, mask, k - 1, nums)) return true;
            }else if(curSum + nums[j] < target){
                if(dfs(curSum + nums[j], mask, k, nums)) return true;
            }
            mask &= ~(1 << j);
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;

        target = sum / k;
        return dfs(0, 0, k, nums);
    }
};