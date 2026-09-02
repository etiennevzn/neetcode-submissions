class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) : parent(n), size(n, 1){
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    bool unionGroups(int u, int v){
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

    int numGroups(){
        int res = 0;
        for(int i = 0; i < parent.size(); ++i){
            if(parent[i] == i) res++;
        }
        return res;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j]) dsu.unionGroups(i, j);
            }
        }

        return dsu.numGroups();
    }
};