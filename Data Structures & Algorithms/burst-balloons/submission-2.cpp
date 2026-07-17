class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int l, int r, vector<int>& nums){
        if(l > r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        
        int maxCount = 0;
        for(int i = l; i <= r; ++i){
            int count = nums[l - 1] * nums[i] * nums[r + 1];
            count += dfs(l, i - 1, nums) + dfs(i + 1, r, nums);
            maxCount = max(maxCount, count);
        }

        memo[l][r] = maxCount;
        return maxCount;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for(int i = 0; i < n; ++i){
            newNums[i + 1] = nums[i];
        }

        memo.resize(n + 2, vector<int>(n + 2, -1));
        return dfs(1, n, newNums);
    }
};
