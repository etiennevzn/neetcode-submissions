class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        int res = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            res++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int city : graph[cur]){
                    if(visited[city]) continue;
                    q.push(city);
                    visited[city] = true;
                }
            }
        }

        return res;
    }
};