class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n);
        unordered_map<int,vector<int>> child;
        unordered_map<int,vector<int>> parents;

        vector<int> dependency(n);
        for(const vector<int>& relation : richer){
            child[relation[0]].push_back(relation[1]);
            parents[relation[1]].push_back(relation[0]);
            dependency[relation[1]]++;
        }
        
        queue<int> pplQueue;
        for(int i = 0; i < n; ++i){
            if(dependency[i] == 0) pplQueue.push(i);
        }

        while(!pplQueue.empty()){
            int cur = pplQueue.front();
            pplQueue.pop();
            int minQuiet = cur;
            for(int parent : parents[cur]){
                if(quiet[ans[parent]] < quiet[minQuiet]) minQuiet = ans[parent];
            }
            ans[cur] = minQuiet;

            for(int children : child[cur]){
                dependency[children]--;
                if(dependency[children] == 0) pplQueue.push(children);
            }
        }

        return ans;
    }
};