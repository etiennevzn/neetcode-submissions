class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(size_t i = 0; i < edges.size(); ++i){
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            graph[a].emplace_back(b, p);
            graph[b].emplace_back(a, p);
        }

        vector<double> maxP(n);
        queue<int> nodeQ;
        nodeQ.push(start_node);
        maxP[start_node] = 1.0;

        while(!nodeQ.empty()){
            int cur = nodeQ.front();
            nodeQ.pop();
            double curP = maxP[cur];
            for(const auto& [nei, w] : graph[cur]){
                double newP =  curP * w;
                if(newP > maxP[nei]){
                    maxP[nei] = newP;
                    nodeQ.push(nei);
                }
            }
        }

        return maxP[end_node];
    }
};