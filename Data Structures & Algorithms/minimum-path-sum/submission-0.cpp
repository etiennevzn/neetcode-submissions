class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> sumPath(ROWS, vector<int>(COLS, INT_MAX));
        sumPath[0][0] = grid[0][0];
        minHeap.push({grid[0][0], 0, 0});
        vector<pair<int, int>> dirs = {{1,0}, {0,1}};

        while(!minHeap.empty()){
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int sum = curr[0], r = curr[1], c = curr[2];

            for(const auto& dir : dirs){
                int nr = r + dir.first, nc = c + dir.second;
                if(sumPath[r][c] < sum) continue;
                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS){
                    int newSum = sumPath[r][c] + grid[nr][nc];
                    if(newSum < sumPath[nr][nc]){
                        sumPath[nr][nc] = newSum;
                        minHeap.push({newSum, nr, nc});
                    }
                }
            }
        }

        return sumPath[ROWS - 1][COLS - 1];
    }
};