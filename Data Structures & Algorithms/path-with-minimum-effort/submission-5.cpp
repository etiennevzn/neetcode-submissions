class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> efforts(ROWS, vector<int>(COLS, INT_MAX));
        efforts[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        minHeap.push({0, 0, 0});

        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!minHeap.empty()){
            vector<int> curr = minHeap.top();
            minHeap.pop();

            int effort = curr[0], r = curr[1], c = curr[2];
            //if(r == ROWS - 1 && c == COLS - 1) return effort;
            if(effort > efforts[r][c]) continue;

            for(const auto& dir : dirs){
                int nr = r + dir.first, nc = c + dir.second;
                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS){
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    if(newEffort < efforts[nr][nc]){
                        efforts[nr][nc] = newEffort;
                        minHeap.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return efforts[ROWS - 1][COLS - 1];
    }
};