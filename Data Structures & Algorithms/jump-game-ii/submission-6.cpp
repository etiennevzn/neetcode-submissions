class Solution {
private:
    vector<int> memo;
    int dfs(int i, vector<int>& nums){
        if(i == nums.size() - 1) return 0;
        if(memo[i] != -1) return memo[i];

        int res = nums.size();
        for(int j = 1; j <= nums[i]; ++j){
            if(i + j < nums.size()) res = min(res, 1 + dfs(i + j, nums));
        }
        memo[i] = res;
        return res;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, -1);
        return dfs(0, nums);
    }
};
