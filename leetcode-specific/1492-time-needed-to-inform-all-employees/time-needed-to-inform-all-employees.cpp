class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int numMin = 0;

        unordered_map<int,vector<int>> graph;
        for(size_t i = 0; i < manager.size(); ++i){
            if(i == headID) continue;
            graph[manager[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.emplace(headID, 0);

        while(!q.empty()){
            auto [cur, time] = q.front();
            q.pop();
            numMin = max(numMin, time);
            int infTime = informTime[cur];
            
            for(size_t i = 0; i < graph[cur].size(); ++i){
                int nei = graph[cur][i];
                q.emplace(nei, time + infTime);
            }
        }

        return numMin;
    }
};