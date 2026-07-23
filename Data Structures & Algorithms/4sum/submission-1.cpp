class Solution {
private:
    vector<vector<int>> res;
    void dfs(int i, vector<int>& curRes, long long curSum, vector<int>& nums, int target){
        if(curRes.size() == 4){
            if(curSum == target) res.push_back(curRes);
            return;
        }

        for(int j = i + 1; j < nums.size(); ++j){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            curRes.push_back(nums[j]);
            dfs(j, curRes, curSum + nums[j], nums, target);
            curRes.pop_back();
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> curRes;
        sort(nums.begin(), nums.end());
        dfs(-1, curRes, 0, nums, target);
        return res;
    }
};