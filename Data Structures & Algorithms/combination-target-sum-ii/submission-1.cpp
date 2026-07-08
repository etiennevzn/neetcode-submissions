class Solution {
private:
    vector<vector<int>> res;

    void backtrack(int start, int curSum, vector<int>& cur, vector<int>& candidates, int target){
        if(curSum == target){
            res.push_back(cur);
            return;
        }

        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i] == candidates[i-1]) continue;
            if(curSum + candidates[i] > target) break;
            cur.push_back(candidates[i]);
            backtrack(i+1, curSum + candidates[i], cur, candidates, target);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(0,0,cur,candidates,target);
        return res;
    }
};
