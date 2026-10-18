class Solution {
private:
    vector<int> pathBob;
    unordered_map<int,int> unlockTime;

    void dfsBob(int cur, int parent, vector<int>& path, const vector<vector<int>>& graph){
        if(!pathBob.empty()) return;

        path.push_back(cur);

        if(cur == 0){
            pathBob = path;
            return;
        }

        for(int nei : graph.at(cur)){
            if(nei == parent) continue;
            dfsBob(nei, cur, path, graph);
        }
        path.pop_back();
    }

    int dfsAlice(int cur, int parent, int time, const vector<int>& amount, const vector<vector<int>>& graph){
        int gate = amount[cur];
        if(unlockTime.count(cur)){
            if(time > unlockTime.at(cur)){
                gate = 0;
            }else if(time == unlockTime.at(cur)){
                gate /= 2;
            }
        }

        int res = INT_MIN;
        for(int nei : graph.at(cur)){
            if(nei == parent) continue;
            res = max(res, gate + dfsAlice(nei, cur, time + 1, amount, graph));
        }

        return res == INT_MIN ? gate : res;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for(const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> path;
        dfsBob(bob, -1, path, graph);
        for(size_t i = 0; i < pathBob.size(); ++i){
            unlockTime[pathBob[i]] = i;
        }

        return dfsAlice(0, -1, 0, amount, graph);
    }
};
