class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> graph;

        for(const vector<int>& route : routes){
            int n = route.size();
            unordered_set<int> stops = unordered_set<int>(route.begin(), route.end());

            for(int i = 0; i < n; ++i){
                stops.erase(route[i]);
                for(int stop : stops) graph[route[i]].insert(stop);
                stops.insert(route[i]);
            }
        }

        queue<int> stopsQueue;
        unordered_set<int> visited;
        int buses = 0;
        stopsQueue.push(source);
        visited.insert(source);

        while(!stopsQueue.empty()){
            for(int i = stopsQueue.size(); i > 0; --i){
                int curr = stopsQueue.front();
                stopsQueue.pop();
                if(curr == target) return buses;

                for(int nei : graph[curr]){
                    if(visited.count(nei)) continue;
                    visited.insert(nei);
                    stopsQueue.push(nei);
                }
            }
            buses++;
        }

        return -1;
    }
};