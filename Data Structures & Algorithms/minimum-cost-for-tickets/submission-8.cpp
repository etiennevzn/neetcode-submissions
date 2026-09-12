class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; --i){
            int res = INT_MAX, cost = 0, j = i;
            for(int limit : {1, 7, 30}){
                while(j < n && days[j] < days[i] + limit) j++;
                res = min(res, costs[cost] + dp[j]);
                cost++;
            }
            dp[i] = res;
        }

        return dp[0];
    }
};