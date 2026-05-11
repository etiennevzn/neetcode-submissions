class Solution {
private:
    vector<int> memo;
    int dfs(vector<int>& nums, int i){
        if(i == nums.size()) return 0;
        if(memo[i] != -1) return memo[i];

        return memo[i] = max(nums[i], nums[i] + dfs(nums, i+1));
    }
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        memo.resize(nums.size(), -1);

        for(int i = 0; i < nums.size(); ++i){
            maxi = max(maxi, dfs(nums,i));
        }
        return maxi;
    }
};
