class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        
        vector<bool> visited(n, false);
        queue<int> q;

        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            res++;
            q.push(i);
            visited[i] = true;

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int nei = 0; nei < n; ++nei){
                    if(visited[nei] || isConnected[cur][nei] == 0) continue;
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }

        return res;
    }
};