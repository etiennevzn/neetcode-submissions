class Solution {
    int dfs(int i, int cur, vector<int>& nums){
        if(i == nums.size()) return cur;
        return dfs(i + 1, cur, nums) + dfs(i + 1, cur ^ nums[i], nums);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }
};