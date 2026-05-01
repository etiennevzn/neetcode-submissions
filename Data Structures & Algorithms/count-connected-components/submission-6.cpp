class Solution {
    void dfs(vector<bool>& visited, int parent, int cur, vector<vector<int>>& graph){
        if(visited[cur]) return;

        visited[cur] = true;
        for(int nei : graph[cur]){
            if(nei != parent){
                dfs(visited, cur, nei, graph);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        int res = 0;

        vector<vector<int>> graph(n);
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                res++;
                dfs(visited, -1, i, graph);
            }
        }

        return res;
    }
};
