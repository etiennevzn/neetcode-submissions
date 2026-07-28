class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return {0};

        vector<int> indegrees(n);
        vector<vector<int>> graph(n);

        for(const auto& edge : edges){
            int a = edge[0], b = edge[1];
            indegrees[a]++;
            indegrees[b]++;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> leaves;
        for(int i = 0; i < n; ++i){
            if(indegrees[i] == 1) leaves.push(i);
        }

        vector<int> res;
        while(!leaves.empty()){
            if(n <= 2){
                res.push_back(leaves.front());
                leaves.pop();
                continue;
            }

            int numLeaves = leaves.size();
            for(int i = 0; i < numLeaves; ++i){
                int curr = leaves.front();
                leaves.pop();
                n--;
                for(int nei : graph[curr]){
                    if(--indegrees[nei] == 1) leaves.push(nei);
                }
            }
        }

        return res;
    }
};