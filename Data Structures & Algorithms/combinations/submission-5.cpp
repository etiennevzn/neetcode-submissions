class Solution {
    vector<vector<int>> res;

    void dfs(int start, vector<int>& cur, int k, int n){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }

        for(int i = start; i <= n; ++i){
            cur.push_back(i);
            dfs(i + 1, cur, k, n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(1, cur, k, n);
        return res;
    }
};