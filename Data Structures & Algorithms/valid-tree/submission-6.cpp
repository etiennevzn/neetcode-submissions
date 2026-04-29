class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false;

        vector<vector<int>> graph(n);
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<vector<int>> q;
        q.push({0,-1});

        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int node = cur[0], parent = cur[1];

            if(visited.count(node)) return false;
            visited.insert(node);
            for(int nei : graph[node]){
                if(nei != parent) q.push({nei,node});
            }
        }

        return visited.size() == n;
    }
};
