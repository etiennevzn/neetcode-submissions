class Solution {
private:
    int dfs(int employee, const unordered_map<int,vector<int>>& graph, const vector<int>& informTime){
        if(!graph.count(employee)) return 0;

        int inform = 0;
        int added = informTime[employee];
        for(size_t i = 0; i < graph.at(employee).size(); ++i){
            inform = max(inform, added + dfs(graph.at(employee)[i], graph, informTime));
        }

        return inform;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int numMin = 0;

        unordered_map<int,vector<int>> graph;
        for(size_t i = 0; i < manager.size(); ++i){
            if(i == headID) continue;
            graph[manager[i]].push_back(i);
        }

        return dfs(headID, graph, informTime);
    }
};