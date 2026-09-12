class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        days.push_back(days.back() + 30);
        int n = days.size();
        vector<int> dp(n, 0);
        int last7 = n, last30 = n;

        for(int i = n - 2; i >= 0; --i){
            dp[i] = costs[0] + dp[i + 1];
            
            while(last7 > i + 1 && days[last7 - 1] >= days[i] + 7) last7--;
            dp[i] = min(dp[i], costs[1] + dp[last7]);

            while(last30 > i + 1 && days[last30 - 1] >= days[i] + 30) last30--;
            dp[i] = min(dp[i], costs[2] + dp[last30]);
        }

        return dp[0];
    }
};