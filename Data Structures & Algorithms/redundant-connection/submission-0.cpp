class DSU {
private:
    vector<int> Size, Parent;
public:
    DSU(int n){
        Size.resize(n+1);
        Parent.resize(n+1);
        for(int i = 0; i < n; ++i){
            Size[i] = 1;
            Parent[i] = i;
        }
    }

    int find(int n){
        if(Parent[n] != n){
            Parent[n] = find(Parent[n]);
        }
        return Parent[n];
    }

    bool unionNodes(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(Size[pu] >= Size[pv]){
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }else{
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for(const auto& edge : edges){
            if(!dsu.unionNodes(edge[0], edge[1])) return edge;
        }

        return {};
    }
};
