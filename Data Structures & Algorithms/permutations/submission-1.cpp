class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<bool>& taken, vector<int>& cur, vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(taken[i]) continue;
            cur.push_back(nums[i]);
            taken[i] = true;
            backtrack(taken, cur, nums);
            taken[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> cur;
        vector<bool> taken(nums.size(), false);
        backtrack(taken, cur, nums);
        return res;
    }
};
