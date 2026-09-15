class Solution {
private:
    vector<vector<int>> memo;
    vector<int> dfs(int i, const vector<int>& nums){
        if(!memo[i].empty()) return memo[i];

        vector<int> res = {nums[i]};
        for(int j = i + 1; j < nums.size(); ++j){
            if(nums[j] % nums[i] == 0){
                vector<int> tmp = {nums[i]};
                vector<int> added = dfs(j, nums);
                tmp.insert(tmp.end(), added.begin(), added.end());
                if(tmp.size() > res.size()) res = tmp;
            }
        }

        return memo[i] = res;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        memo.resize(n);

        vector<int> res;
        for(int i = 0; i < n; ++i){
            vector<int> tmp = dfs(i, nums);
            if(tmp.size() > res.size()) res = tmp;
        }

        return res;
    }
};