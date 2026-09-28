class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        int n = envelopes.size();

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> nums;
        for(const auto& e : envelopes){
            nums.push_back(e[1]);
        }

        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; --i){
            int len = 1;
            for(int j = i + 1; j < n; ++j){
                if(nums[j] > nums[i]) len = max(len, 1 + dp[j]);
            }
            dp[i] = len;
        }

        return *max_element(dp.begin(), dp.end());
    }
};