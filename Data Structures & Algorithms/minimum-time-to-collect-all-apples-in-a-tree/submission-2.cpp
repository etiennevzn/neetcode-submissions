class Solution {
private:
    int dfs(int v, int parent, const vector<vector<int>>& graph, const vector<bool>& hasApple){
        int res = 0;
        for(int nei : graph[v]){
            if(nei == parent) continue;
            int childCost = dfs(nei, v, graph, hasApple);
            if(childCost > 0 || hasApple[nei]){
                res += 2 + childCost;
            }
        }

        return res;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, graph, hasApple);
    }
};