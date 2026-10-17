class Solution {
private:
    int components;
    unordered_map<int,int> parent;

    int find(int coord){
        if(!parent.count(coord)){
            parent[coord] = coord;
            components++;
        }
        if(parent[coord] != coord) parent[coord] = find(parent[coord]);
        return parent[coord];
    }

    void unite(int coordA, int coordB){
        int pa = find(coordA), pb = find(coordB);
        if(pa != pb){
            parent[pb] = pa;
            components--;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        components = 0;

        for(const vector<int>& stone : stones){
            unite(stone[0], - stone[1] - 1);
        }

        return n - components;
    }
};