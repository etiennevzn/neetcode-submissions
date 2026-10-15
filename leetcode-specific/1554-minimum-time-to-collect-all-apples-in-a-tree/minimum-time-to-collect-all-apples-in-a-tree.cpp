class Solution {
private:
    int res = 0;

    bool dfs(int curNode, int parent, const unordered_map<int,vector<int>>& graph, const vector<bool>& hasApple){
        bool subHasApple = hasApple[curNode];
        for(int nei : graph.at(curNode)){
            if(nei == parent) continue;
            if(dfs(nei, curNode, graph, hasApple)){
                res += 2;
                subHasApple = true;
            }
        }

        return subHasApple;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        if(n == 1) return 0;

        unordered_map<int,vector<int>> graph;
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, graph, hasApple);
        
        return res;
    }
};