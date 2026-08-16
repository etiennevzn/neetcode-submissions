class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> diff(ROWS, vector<int>(COLS, INT_MAX));
        diff[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0, -1}};
        minHeap.push({0, 0, 0});

        while(!minHeap.empty()){
            vector<int> cur = minHeap.top();
            minHeap.pop();
            int curDiff = cur[0], r = cur[1], c = cur[2];

            if(r == ROWS - 1 && c == COLS - 1) return curDiff;

            if(curDiff > diff[r][c]) continue;
            for(const pair<int, int>& dir : dirs){
                int nr = r + dir.first, nc = c + dir.second;
                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS){
                    int newDiff = max(curDiff, abs(heights[r][c] - heights[nr][nc]));
                    if(newDiff < diff[nr][nc]){
                        diff[nr][nc] = newDiff;
                        minHeap.push({newDiff, nr, nc});
                    }
                }
            }
        }

        return INT_MAX;
    }
};