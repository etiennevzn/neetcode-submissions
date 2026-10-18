class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ROWS = maze.size();
        int COLS = maze[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        int distance = 0;
        queue<pair<int,int>> cellQueue;
        int enR = entrance[0], enC = entrance[1];
        cellQueue.emplace(enR, enC);
        maze[enR][enC] = '+';

        while(!cellQueue.empty()){
            for(int i = cellQueue.size(); i > 0; --i){
                auto [r, c] = cellQueue.front();
                cellQueue.pop();
                if(r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1){
                    if(r != enR || c != enC) return distance;
                }

                for(const auto& [dr, dc] : dirs){
                    int nr = r + dr, nc = c + dc;
                    if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || maze[nr][nc] == '+') continue;
                    cellQueue.emplace(nr, nc);
                    maze[nr][nc] = '+';
                }
            }
            distance++;
        }


        return -1;
    }
};