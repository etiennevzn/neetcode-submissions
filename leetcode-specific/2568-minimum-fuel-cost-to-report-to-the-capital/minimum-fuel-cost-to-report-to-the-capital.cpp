class Solution {
private:
    long long fuel;
    int dfs(int cur, int parent, const unordered_map<int,vector<int>>& graph, int seats){
        int representatives = 1;

        for(int nei : graph.at(cur)){
            if(nei == parent) continue;
            representatives += dfs(nei, cur, graph, seats);
        }

        if(cur != 0) fuel += ceil((double)representatives / seats);

        return representatives;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if(roads.empty()) return 0;
        fuel = 0;

        unordered_map<int,vector<int>> graph;
        for(const auto& road : roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        dfs(0, -1, graph, seats);

        return fuel;
    }
};