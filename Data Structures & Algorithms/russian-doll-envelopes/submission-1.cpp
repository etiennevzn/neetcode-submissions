class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int prevIdx, const vector<vector<int>>& envelopes){
        if(i == envelopes.size()) return 0;
        if(memo[i][prevIdx + 1] != -1) return memo[i][prevIdx + 1];

        int take = 0;
        if(prevIdx == -1 || envelopes[i][1] > envelopes[prevIdx][1]){
            take = 1 + dfs(i + 1, i, envelopes);
        }

        int leave = dfs(i + 1, prevIdx, envelopes);
        return memo[i][prevIdx + 1] = max(take, leave);
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        int n = envelopes.size();
        memo.resize(n, vector<int>(n + 1, -1));

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);

        return dfs(0, -1, envelopes);
    }
};