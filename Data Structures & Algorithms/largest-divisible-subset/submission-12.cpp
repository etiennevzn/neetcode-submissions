class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n);
        vector<int> final = dp[n - 1];

        for(int i = n - 1; i >= 0; --i){
            vector<int> res = {nums[i]};
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[j] % nums[i] == 0){
                    vector<int> tmp = {nums[i]};
                    vector<int> added = dp[j];
                    tmp.insert(tmp.end(), added.begin(), added.end());
                    if(tmp.size() > res.size()) res = tmp;
                }
            }
            dp[i] = res;
            if(dp[i].size() > final.size()) final = dp[i];
        }

        return final;
    }
};