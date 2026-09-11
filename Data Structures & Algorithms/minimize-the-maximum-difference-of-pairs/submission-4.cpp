class Solution {
private:    
    vector<vector<int>> memo;
    int dfs(int i, int p, const vector<int>& nums){
        if(p == 0) return 0;
        if(i >= nums.size() - 1) return INT_MAX;
        if(memo[i][p] != -1) return memo[i][p];

        int take = max(abs(nums[i] - nums[i + 1]), dfs(i + 2, p - 1, nums));
        int skip = dfs(i + 1, p, nums);

        return memo[i][p] = min(take, skip);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        memo.resize(nums.size() - 1, vector<int>(p + 1, -1));
        sort(nums.begin(), nums.end());
        return dfs(0, p, nums);
    }
};