class DSU{
private:
    vector<int> Parent;
    vector<int> Sizes;
    int comps;

public:
    DSU(int n){
        comps = n;
        Parent.resize(n);
        Sizes.resize(n, 1);
        for(int i = 0; i < n; ++i){
            Parent[i] = i;
        }
    }

    int find(int i){
        if(Parent[i] != i){
            Parent[i] = find(Parent[i]);
        }
        return Parent[i];
    }

    void unionSets(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(Sizes[pu] < Sizes[pv]) swap(pu,pv);

        Parent[pv] = pu;
        Sizes[pu] += Sizes[pv];
        comps--;
    }

    int getComps(){return comps;}
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(const vector<int>& edge : edges){
            dsu.unionSets(edge[0], edge[1]);
        }

        return dsu.getComps();
    }
};
