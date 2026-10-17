class Solution {
private:
    int dfs(int cur, const vector<vector<int>>& graph, unordered_set<int>& visited){
        if(visited.count(cur)) return 0;

        visited.insert(cur);
        int res = 1;
        for(int nei : graph.at(cur)){
            if(visited.count(nei)) continue;
            res += dfs(nei, graph, visited);
        }

        return res;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);

        for(int i = 0; i < n; ++i){
            int row = stones[i][0], col = stones[i][1];
            for(int j = i +1; j < n; ++j){
                if(stones[j][0] == row || stones[j][1] == col){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        unordered_set<int> visited;
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(visited.count(i)) continue;
            res += dfs(i, graph, visited) - 1;
        }

        return res;
    }
};