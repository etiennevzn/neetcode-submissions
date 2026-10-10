class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> graph;
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> nodesQ;
        unordered_set<int> visited;
        nodesQ.push(0);
        visited.insert(0);

        while(!nodesQ.empty()){
            int cur = nodesQ.front();
            nodesQ.pop();
            for(int nei : graph[cur]){
                if(visited.count(nei)) continue;
                nodesQ.push(nei);
                visited.insert(nei);
            }
        }

        return visited.size() == n;
    }
};
