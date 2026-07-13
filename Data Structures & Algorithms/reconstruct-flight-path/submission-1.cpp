class Solution {
private:
    bool dfs(const string& from, vector<string>& res, unordered_map<string, vector<string>>& graph, int targetLen){
        if(res.size() == targetLen) return true;
        if(!graph.count(from)) return false;

        vector<string> temp = graph[from]; 
        for(int i = 0; i < temp.size(); ++i){
            res.push_back(temp[i]);
            graph[from].erase(graph[from].begin() + i);
            if(dfs(temp[i], res, graph, targetLen)) return true;
            res.pop_back();
            graph[from].insert(graph[from].begin() + i, temp[i]);
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        sort(tickets.begin(), tickets.end());
        for(const auto& ticket : tickets){
            graph[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res = {"JFK"};
        dfs("JFK", res, graph, tickets.size() + 1);
        return res;
    }
};
