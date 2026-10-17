class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n);
        vector<vector<int>> poorer(n);

        vector<int> dependency(n);
        for(const vector<int>& relation : richer){
            poorer[relation[0]].push_back(relation[1]);
            dependency[relation[1]]++;
        }
        
        queue<int> pplQueue;
        for(int i = 0; i < n; ++i){
            ans[i] = i;
            if(dependency[i] == 0) pplQueue.push(i);
        }

        while(!pplQueue.empty()){
            int cur = pplQueue.front();
            pplQueue.pop();
        
            for(int poor : poorer[cur]){
                if(quiet[ans[cur]] < quiet[ans[poor]]) ans[poor] = ans[cur];
                dependency[poor]--;
                if(dependency[poor] == 0) pplQueue.push(poor);
            }
        }

        return ans;
    }
};