class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(target == source) return 0;

        unordered_map<int, vector<int>> stops;
        for(int route = 0; route < routes.size(); ++route){
            for(int stop : routes[route]){
                stops[stop].push_back(route);
            }
        }

        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;
        queue<int> stopsQueue;
        stopsQueue.push(source);
        visitedStops.insert(source);
        int buses = 0;

        while(!stopsQueue.empty()){
            for(int i = stopsQueue.size(); i > 0; --i){
                int curr = stopsQueue.front();
                stopsQueue.pop();
                if(curr == target) return buses;

                for(int bus : stops[curr]){
                    if(visitedRoutes.count(bus)) continue;
                    visitedRoutes.insert(bus);
                    for(int nei : routes[bus]){
                        if(visitedStops.count(nei)) continue;
                        visitedStops.insert(nei);
                        stopsQueue.push(nei);
                    }
                }
            }
            buses++;
        }

        return -1;
    }
};