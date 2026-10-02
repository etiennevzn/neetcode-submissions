class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(size_t i = 0; i < edges.size(); ++i){
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            graph[a].emplace_back(b, p);
            graph[b].emplace_back(a, p);
        }

        unordered_set<int> visited;
        priority_queue<pair<double, int>> pHeap;
        pHeap.emplace(1.0, start_node);

        while(!pHeap.empty()){
            auto [p, node] = pHeap.top();
            pHeap.pop();
            if(node == end_node) return p;
            
            if(visited.count(node)) continue;
            visited.insert(node);
            for(const auto& [nei, w] : graph[node]){
                if(visited.count(nei)) continue;
                pHeap.emplace(w * p, nei);
            }
        }

        return 0;
    }
};