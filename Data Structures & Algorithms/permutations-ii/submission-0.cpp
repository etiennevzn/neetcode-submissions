class Solution {
    vector<vector<int>> res;

    void dfs(vector<int>& cur, vector<bool>& used, vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); ++i){
            if(used[i] || seen.count(nums[i])) continue;
            used[i] = true;
            seen.insert(nums[i]);
            cur.push_back(nums[i]);
            dfs(cur, used, nums);
            used[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        dfs(cur, used, nums);
        return res;
    }
};