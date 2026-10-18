class Solution {
private:
    vector<int> memo;
    int dfs(int i, const vector<vector<int>>& jobs){
        if(i == jobs.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int end = jobs[i][1];
        int next = i + 1;
        while(next < jobs.size() && jobs[next][0] < end) next++;

        return memo[i] = max(jobs[i][2] + dfs(next, jobs), dfs(i + 1, jobs));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i = 0; i < n; ++i){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        memo.assign(n, -1);

        return dfs(0, jobs);
    }
};