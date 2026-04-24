class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int target, int i, vector<int>& cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target < 0 || i >= nums.size()) return;

        cur.push_back(nums[i]);
        backtrack(nums, target-nums[i], i, cur);
        cur.pop_back();
        backtrack(nums, target, i+1, cur);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, 0, cur);
        return res;
    }
};
