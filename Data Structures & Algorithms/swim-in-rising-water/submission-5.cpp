class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        set<pair<int,int>> visited;
        int DIM = grid.size();

        minHeap.push({grid[0][0], 0, 0});
        visited.insert({0,0});

        while(!minHeap.empty()){
            vector<int> cur = minHeap.top();
            int t = cur[0], r = cur[1], c = cur[2];
            minHeap.pop();
            if(r == DIM - 1 && c == DIM - 1) return t;

            for(const auto& dir : directions){
                int nr = r + dir.first, nc = c + dir.second;
                if(nr < 0 || nr >= DIM || nc < 0 || nc >= DIM || visited.count({nr,nc})) continue;
                visited.insert({nr,nc});
                minHeap.push({max(t, grid[nr][nc]), nr, nc});
            }
        }

        return DIM*DIM;
    }
};
