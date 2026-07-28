class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); ++i){
            const vector<string>& eq = equations[i];
            graph[eq[0]].push_back({eq[1], values[i]});
            graph[eq[1]].push_back({eq[0], 1.0 / values[i]});
        }

        vector<double> res;
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        for(const auto& qu : queries){
            if(!graph.count(qu[0]) || !graph.count(qu[1])){
                res.push_back(-1.0);
                continue;
            }
            q = {};
            q.push({qu[0], 1.0});   
            bool found = false;
            visited = {};
            visited.insert(qu[0]);
            while(!q.empty()){
                pair<string, double> curr = q.front();
                q.pop();
                if(curr.first == qu[1]){
                    res.push_back(curr.second);
                    found = true;
                    break;
                }
                if(!graph.count(curr.first)) continue;
                for(const auto& nei : graph[curr.first]){
                    if(visited.count(nei.first)) continue;
                    visited.insert(nei.first);
                    q.push({nei.first, nei.second * curr.second});
                }
            }
            if(!found) res.push_back(-1.0);
        }

        return res;
    }
};