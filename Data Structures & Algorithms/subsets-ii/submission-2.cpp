class Solution {
private:
    vector<vector<int>> res;

    void backtrack(int start, vector<int>& cur, vector<int>& nums){
        if(cur.size() > nums.size()) return;
        res.push_back(cur);

        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(i+1, cur, nums);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(0, cur, nums);
        return res;
    }
};
