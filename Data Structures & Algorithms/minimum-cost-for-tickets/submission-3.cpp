class Solution {
private:
    vector<int> memo;
    int dfs(int i, const vector<int>& days, const vector<int>& costs){
        if(i == days.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int res = INT_MAX, cost = 0, j = i;

        for(int limit : {1, 7, 30}){
            while(j < days.size() && days[j] < days[i] + limit) j++;
            res = min(res, costs[cost] + dfs(j, days, costs));
            cost++;
        }

        return memo[i] = res;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.resize(days.size(), -1);
        return dfs(0, days, costs);
    }
};