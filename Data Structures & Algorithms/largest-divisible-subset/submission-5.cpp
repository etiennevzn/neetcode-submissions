class Solution {
private:
    vector<vector<vector<int>>> memo;
    vector<int> dfs(int i, int prevIdx, const vector<int>& nums){
        if(i == nums.size()) return {};
        if(!memo[i][prevIdx + 1].empty()) return memo[i][prevIdx + 1];

        vector<int> res = dfs(i+1, prevIdx, nums);
        if(prevIdx == -1 || nums[i] % nums[prevIdx] == 0){
            vector<int> tmp = {nums[i]};
            vector<int> added = dfs(i + 1, i, nums);
            tmp.insert(tmp.end(), added.begin(), added.end());
            if(tmp.size() > res.size()) res = tmp;
        }

        return memo[i][prevIdx + 1] = res;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        memo.resize(n, vector<vector<int>>(n + 1));
        return dfs(0, -1, nums);
    }
};