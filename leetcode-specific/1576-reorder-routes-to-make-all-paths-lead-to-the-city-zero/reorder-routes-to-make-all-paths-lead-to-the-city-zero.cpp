class Solution {
private:
    int dfs(int cur, int parent, const vector<vector<int>>& graph){
        int res = 0;
        for(int nei : graph[cur]){
            if(nei == parent || -nei == parent) continue;
            if(nei > 0) res++;
            if(nei < 0) nei = -nei;
            res += dfs(nei, cur, graph);
        }

        return res;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(const auto& connection : connections){
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(-connection[0]);
        }

        return dfs(0, INT_MIN, graph);
    }
};