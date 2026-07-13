class DSU {
private:
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n), Size(n, 1){
        for(int i = 0; i < n; ++i) Parent[i] = i;
    } 

    int find(int n){
        if(Parent[n] != n){
            Parent[n] = find(Parent[n]);
        }
        return Parent[n];
    }

    bool unionSets(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(Size[pu] <= Size[pv]) swap(pu, pv);
        Parent[pv] = pu;
        Size[pu] += Size[pv];
        return true;
    }

};

class Solution {
private:
    int computeDistance(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        DSU dsu(n);

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int dist = computeDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int res = 0;
        for(const auto& edge : edges){
            if(!dsu.unionSets(edge[1], edge[2])) continue;
            res += edge[0];
        }

        return res;
    }
};
