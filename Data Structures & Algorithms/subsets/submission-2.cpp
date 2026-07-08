class Solution {
private:
    vector<vector<int>> res;

    void backtrack(int start, vector<int>& cur, vector<int>& nums){
        res.push_back(cur);

        for(int i = start; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            backtrack(i+1, cur, nums);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> cur = {};
        backtrack(0, cur, nums);
        return res;
    }
};
