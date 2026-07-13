class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for(const vector<int>& edge : times){
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, k});
        unordered_set<int> visited;
        int t = 0;

        while(!minHeap.empty()){
            auto [time, cur] = minHeap.top();
            minHeap.pop();
            if(visited.count(cur)) continue;
            visited.insert(cur);
            t = time;

            if(graph.count(cur)){
                for(const pair<int,int>& nei : graph[cur]){
                    if(!visited.count(nei.first)){
                        minHeap.push({time + nei.second, nei.first});
                    }
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
