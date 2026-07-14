class Solution {
    bool dfs(int i, int cur, int target, vector<int>& nums){
        if(cur == target) return true;
        if(cur > target) return false;

        for(int j = i+1; j < nums.size(); ++j){
            cur += nums[i];
            if(dfs(j, cur, target, nums)) return true;
            cur -= nums[i];
            if(dfs(j, cur, target, nums)) return true;
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        
        return dfs(0, 0, sum / 2, nums);
    }
};
