class Solution {
private:
    int dfs(vector<int>& nums, int i){
        if(i == nums.size()) return 0;

        return max(nums[i], nums[i] + dfs(nums, i+1));
    }
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            maxi = max(maxi, dfs(nums,i));
        }
        return maxi;
    }
};
