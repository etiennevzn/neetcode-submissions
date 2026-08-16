class Solution {
    vector<vector<int>> res;

    void dfs(vector<int>& cur, vector<bool>& used, vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(cur, used, nums);
            used[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(cur, used, nums);
        return res;
    }
};