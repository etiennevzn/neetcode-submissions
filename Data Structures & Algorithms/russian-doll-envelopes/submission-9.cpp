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

        vector<int> dp;
        dp.push_back(nums[0]);
        int LIS = 1;

        for(int i = 1; i < n; ++i){
            if(nums[i] > dp.back()){
                LIS++;
                dp.push_back(nums[i]);
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }

        return LIS;
    }
};