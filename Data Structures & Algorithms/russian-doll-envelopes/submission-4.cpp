class Solution {
private:
    vector<int> memo;
    int n;
    int dfs(int i, const vector<int>& nums){
        if(memo[i] != -1) return memo[i];
        int len = 1;
        for(int j = i + 1; j < n; ++j){
            if(nums[j] > nums[i]){
                len = max(len, 1 + dfs(j, nums));
            }
        }        

        return memo[i] = len;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        n = envelopes.size();
        memo.resize(n, -1);

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> nums;
        for(const auto& e : envelopes){
            nums.push_back(e[1]);
        }

        int res = 1;
        for(int i = 0; i < n; ++i){
            res = max(res, dfs(i, nums));
        }

        return res;
    }
};