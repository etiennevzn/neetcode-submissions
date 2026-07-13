class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for(size_t i = 0; i < times.size(); ++i){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX);
        queue<int> q;
        dist[k] = 0;
        q.push(k);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const pair<int,int>& nei : graph[cur]){
                if (dist[cur] + nei.second < dist[nei.first]) {
                    dist[nei.first] = dist[cur] + nei.second;
                    q.push(nei.first);
                }
            }
        }

        return *max_element(dist.begin()+1, dist.end()) == INT_MAX ? -1 : *max_element(dist.begin()+1, dist.end());
    }
};
