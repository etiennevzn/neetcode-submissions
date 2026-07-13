class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        for(int i = 0; i < n-1; ++i){
            for(const vector<int>& edge : times){
                int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
                if(dist[u] != INT_MAX) dist[v] = min(dist[v], dist[u] + w);
            }
        }
        
        int res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
