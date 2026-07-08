class Solution {
private:
    vector<vector<int>> res;

    void backtrack(unordered_set<int>& taken, vector<int>& cur, vector<int>& nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(taken.count(i)) continue;
            cur.push_back(nums[i]);
            taken.insert(i);
            backtrack(taken, cur, nums);
            taken.erase(i);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> cur;
        unordered_set<int> taken;
        backtrack(taken, cur, nums);
        return res;
    }
};
