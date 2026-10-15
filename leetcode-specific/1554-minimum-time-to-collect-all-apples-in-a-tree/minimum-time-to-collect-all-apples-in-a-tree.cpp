class Solution {
private:
    int dfs(int curNode, int parent, const unordered_map<int,vector<int>>& graph, const vector<bool>& hasApple){
        int cost = 0;
        for(int nei : graph.at(curNode)){
            if(nei == parent) continue;
            int childTime = dfs(nei, curNode, graph, hasApple);
            if(childTime > 0 || hasApple[nei]) cost += childTime + 2;
        }

        return cost;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        if(n == 1) return 0;

        unordered_map<int,vector<int>> graph;
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, -1, graph, hasApple);
    }
};