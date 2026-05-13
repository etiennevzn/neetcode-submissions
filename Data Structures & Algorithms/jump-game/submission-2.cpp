class Solution {
private:
    vector<int> memo;
    bool dfs(vector<int>& nums, int idx){
        if(idx >= nums.size()-1) return true;
        if(nums[idx] == 0) return false;
        if(memo[idx] != -1) return memo[idx];
        
        for(int i = 1; i <= nums[idx]; ++i){
            if(dfs(nums,idx+i)) return memo[idx] = true;
        }
        return memo[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(nums,0);
    }
};
