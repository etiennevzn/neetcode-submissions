class Solution {
private:   
    vector<int> memo;
    int dfs(int dayIdx, const vector<int>& days, const vector<int>& costs){
        if(dayIdx == days.size()) return 0;
        if(memo[dayIdx] != -1) return memo[dayIdx];

        int res = costs[0] + dfs(dayIdx + 1, days, costs);
        int next = dayIdx + 1; 
        while(next < days.size() && days[next] <= days[dayIdx] + 6) next++;
        res = min(res, costs[1] + dfs(next, days, costs));
        while(next < days.size() && days[next] <= days[dayIdx] + 29) next++;
        res = min(res, costs[2] + dfs(next, days, costs));

        return memo[dayIdx] = res;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.assign(days.size(), -1);
        return dfs(0, days, costs);
    }
};