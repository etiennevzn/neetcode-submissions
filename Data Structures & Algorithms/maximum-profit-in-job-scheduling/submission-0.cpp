class Solution {
private:
    unordered_map<int, unordered_map<int,int>> memo;
    int dfs(int i, int lastEnd, const vector<vector<int>>& jobs){
        if(i == jobs.size()) return 0;
        if(memo.count(i) && memo[i].count(lastEnd)) return memo[i][lastEnd];

        int maxProfit = 0;
        if(jobs[i][0] >= lastEnd){
            maxProfit = max(maxProfit, jobs[i][2] + dfs(i + 1, jobs[i][1], jobs));
        }
        maxProfit = max(maxProfit, dfs(i + 1, lastEnd, jobs));

        return memo[i][lastEnd] = maxProfit;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i = 0; i < startTime.size(); ++i){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        return dfs(0, 0, jobs);
    }
};