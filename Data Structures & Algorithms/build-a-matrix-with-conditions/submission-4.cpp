class Solution {
private:
    vector<int> topoSort(int k, vector<vector<int>>& conditions){
        vector<vector<int>> graph(k + 1);
        vector<int> numPred(k + 1, 0);

        for(const auto& cond : conditions){
            graph[cond[0]].push_back(cond[1]); 
            numPred[cond[1]]++;
        }

        queue<int> q;
        for(int i = 1; i <= k; ++i){
            if(!numPred[i]) q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int succ : graph[curr]){
                numPred[succ]--;
                if(!numPred[succ]) q.push(succ);
            }
            res.push_back(curr);
        }

        return res;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> rowOrder = topoSort(k, rowConditions);
        if(rowOrder.size() != k) return {};
        vector<int> colOrder = topoSort(k, colConditions);
        if(colOrder.size() != k) return {};

        unordered_map<int, pair<int,int>> coords;

        for(int i = 0; i < k; ++i){
            coords[rowOrder[i]].first = i;
            coords[colOrder[i]].second = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 1; i <= k; ++i){
            res[coords[i].first][coords[i].second] = i;
        }

        return res;
    }
};