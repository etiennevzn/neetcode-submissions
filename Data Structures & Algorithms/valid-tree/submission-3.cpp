class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>& graph, unordered_set<int>& visited){
        if(visited.count(node)) return false;

        visited.insert(node);
        for(int nei : graph[node]){
            if(nei != parent){
                if(!dfs(nei, node, graph, visited)) return false;
            }
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<vector<int>> graph(n);
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        return dfs(0, -1, graph, visited) && visited.size() == n;
    }
};
