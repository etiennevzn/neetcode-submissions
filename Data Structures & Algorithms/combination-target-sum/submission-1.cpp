class Solution {
private:
    vector<vector<int>> res;
    void backtrack(int start, int curSum, vector<int>& cur, vector<int>& nums, int target){
        if(curSum == target){
            res.push_back(cur);
            return;
        }

        for(int i = start; i < nums.size(); ++i){
            if(curSum + nums[i] <= target){
                cur.push_back(nums[i]);
                backtrack(i, curSum + nums[i], cur, nums, target);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        vector<int> solutions = {};
        backtrack(0, 0, solutions, nums, target);
        return res;
    }
};
