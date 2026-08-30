class DSU{
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) : parent(n), size(n, 1){
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        return true;
    }
};

class Solution {
private:
    int kruskal(int n, const vector<vector<int>>& edges, int skip, int force){
        int mstSize = 0, mstWeight = 0;
        DSU dsu(n);

        if(force != -1){
            const auto& edge = edges[force];
            int u = edge[0], v = edge[1];
            dsu.unite(u,v);
            mstWeight += edge[2];
            mstSize++;
            if(mstSize == n - 1) return mstWeight;
        }

        for(int i = 0; i < edges.size(); ++i){
            if(i == skip || i == force) continue;

            const auto& edge = edges[i];
            int u = edge[0], v = edge[1];
            if(dsu.unite(u,v)){
                mstWeight += edge[2];
                mstSize++;
                if(mstSize == n - 1) break;
            }
        }

        return (mstSize != n-1) ? INT_MAX : mstWeight;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2);

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        };

        for(int i = 0; i < edges.size(); ++i){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);

        int baseMST = kruskal(n, edges, -1, -1);

        for(int i = 0; i < edges.size(); ++i){
            int skip = kruskal(n, edges, i, -1);
            if(skip > baseMST){
                res[0].push_back(edges[i][3]);
            }else{
                int force = kruskal(n, edges, -1, i);
                if(force == baseMST) res[1].push_back(edges[i][3]);
            }
        }

        return res;
    }
};