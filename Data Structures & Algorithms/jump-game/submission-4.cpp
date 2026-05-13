class Solution {
private:
    unordered_map<int, bool> memo;
    bool dfs(vector<int>& nums, int idx){
        if(idx == nums.size()-1) return true;
        if(nums[idx] == 0) return false;
        if(memo.count(idx)) return memo[idx];
        
        for(int i = 1; i <= nums[idx]; ++i){
            if(dfs(nums,idx+i)) return memo[idx] = true;
        }
        return memo[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
    }
};
