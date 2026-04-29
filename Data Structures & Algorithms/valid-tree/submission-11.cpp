class DSU {
    vector<int> Parent, Size;
    int comps;
public:
    DSU(int n){
        comps = n;
        Parent.resize(n);
        Size.resize(n);
        for(int i = 0; i < n; ++i){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int components(){return comps;}

    int find(int i){
        if(Parent[i] != i){
            Parent[i] = find(Parent[i]);
        }
        return Parent[i];
    }

    bool unionNodes(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb) return false;

        if(Size[pa] < Size[pb]) swap(pa,pb);

        comps--;
        Size[pa] += Size[pb];
        Parent[pb] = pa;
        return true;
    }
    
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;
        DSU dsu(n);
        for(const vector<int>& edge : edges){
            if(!dsu.unionNodes(edge[0], edge[1])) return false;
        }
        return dsu.components() == 1;
    }
};