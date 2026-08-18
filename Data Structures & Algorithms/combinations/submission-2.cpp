class Solution {
    vector<vector<int>> res;

    void dfs(vector<int>& cur, int k, int n){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }

        for(int i = 1; i <= n; ++i){
            if(!cur.empty() && cur.back() >= i) continue;

            cur.push_back(i);
            dfs(cur, k, n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(cur, k, n);
        return res;
    }
};