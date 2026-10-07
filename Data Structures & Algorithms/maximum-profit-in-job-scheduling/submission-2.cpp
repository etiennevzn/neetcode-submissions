class Solution {
private:
    vector<int> memo;
    int dfs(int i, const vector<vector<int>>& jobs){
        if(i == jobs.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int nextJob = i;
        while(nextJob < jobs.size() && jobs[nextJob][0] < jobs[i][1]) nextJob++;
        int maxProfit = jobs[i][2] + dfs(nextJob, jobs);

        maxProfit = max(maxProfit, dfs(i + 1, jobs));

        return memo[i] = maxProfit;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; ++i){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        memo.assign(n, -1);
        return dfs(0, jobs);
    }
};