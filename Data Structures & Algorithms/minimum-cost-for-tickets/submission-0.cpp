class Solution {
private:
    vector<vector<int>> memo;
    int dfs(int i, int travelLimit, const vector<int>& days, const vector<int>& costs){
        while(i < days.size() && days[i] <= travelLimit) i++;
        if(i == days.size()) return 0;
        if(memo[i][travelLimit] != -1) return memo[i][travelLimit];

        int pass1 = costs[0] + dfs(i, days[i], days, costs);
        int pass7 = costs[1] + dfs(i, days[i] + 6, days, costs); 
        int pass30 = costs[2] + dfs(i, days[i] + 29, days, costs); 

        return memo[i][travelLimit] = min(pass1, min(pass7, pass30));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.resize(days.size(), vector<int>(365, -1));
        return dfs(0, 0, days, costs);
    }
};