class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto& e : edges) {
            int p1 = find(e[0]);
            int p2 = find(e[1]);

            if(p1 == p2) return false; // cycle

            parent[p1] = p2;
        }

        return true;
    }
};
