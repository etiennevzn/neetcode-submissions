class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int numMin = 0;

        unordered_map<int,vector<int>> graph;
        for(size_t i = 0; i < manager.size(); ++i){
            if(i == headID) continue;
            graph[manager[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<pair<int,int>> q;
        q.emplace(headID, 0);
        visited[headID] = true;

        while(!q.empty()){
            auto [cur, time] = q.front();
            q.pop();
            numMin = max(numMin, time);
            int infTime = informTime[cur];
            
            for(size_t i = 0; i < graph[cur].size(); ++i){
                int nei = graph[cur][i];
                if(visited[nei]) continue;
                visited[nei] = true;
                q.emplace(nei, time + infTime);
            }
        }

        return numMin;
    }
};