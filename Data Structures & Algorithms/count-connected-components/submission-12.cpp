class Solution {
private:
    unordered_map<int,vector<int>> graph;

    void dfs(int c, set<int>& visited){
        if(visited.count(c)) return;

        visited.insert(c);
        for(int nei : graph[c]){
            dfs(nei, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        set<int> visited;
        int res = 0;
        for(int c = 0; c < n; ++c){
            if(!visited.count(c)){
                res++;
                dfs(c, visited);
            }
        }

        return res;
    }
};
