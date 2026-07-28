class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(const auto& edge : edges){
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> res;
        unordered_map<int, int> heightMap;
        int minHeight = n;
        int curHeight = 0;
        unordered_set<int> visited;
        queue<int> q;

        for(int root = 0; root < n; ++root){
            q = {};
            visited = {};
            curHeight = 0;
            q.push(root);
            visited.insert(root);
            while(!q.empty()){
                int qSize = q.size();
                for(int i = 0; i < qSize; ++i){
                    int curr = q.front();
                    q.pop();
                    if(!graph.count(curr)) continue;
                    for(int nei : graph[curr]){
                        if(visited.count(nei)) continue;
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
                curHeight++;
            }

            heightMap[root] = curHeight;
            minHeight = min(minHeight, curHeight);
        }

        for(const auto& [root, height] : heightMap){
            if(height == minHeight) res.push_back(root);
        }

        return res;
    }
};