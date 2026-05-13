class Solution {
private:
    bool dfs(vector<int>& nums, int idx){
        if(idx >= nums.size()-1) return true;
        if(nums[idx] == 0) return false;
        
        for(int i = 1; i <= nums[idx]; ++i){
            if(dfs(nums,idx+i)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
    }
};
