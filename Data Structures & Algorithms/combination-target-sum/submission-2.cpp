class Solution {
private:
    vector<vector<int>> res;
    void backtrack(int start, vector<int>& cur, vector<int>& nums, int target){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        for(int i = start; i < nums.size(); ++i){
            if(target - nums[i] >= 0){
                cur.push_back(nums[i]);
                backtrack(i, cur, nums, target - nums[i]);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        vector<int> solutions = {};
        backtrack(0, solutions, nums, target);
        return res;
    }
};
