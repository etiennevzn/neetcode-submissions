class Solution {
private:
    void dfs(const string& from, vector<string>& res, unordered_map<string, vector<string>>& graph){
        while(!graph[from].empty()){
            string to = graph[from].back();
            graph[from].pop_back();
            dfs(to, res, graph);
        }
        res.push_back(from);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
    
        for(const auto& ticket : tickets){
            graph[ticket[0]].push_back(ticket[1]);
        }

        for(auto& [_, to] : graph){
            sort(to.rbegin(), to.rend());
        }

        vector<string> res;
        dfs("JFK", res, graph);
        reverse(res.begin(), res.end());
        return res;
    }
};
