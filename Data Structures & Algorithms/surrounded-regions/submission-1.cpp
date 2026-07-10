class Solution {
private: 
    int ROWS = 0;
    int COLS = 0;
    vector<pair<int,int>> directions{{1,0}, {-1,0}, {0,-1}, {0, 1}};

    void dfs(int r, int c, vector<vector<char>>& board){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O') return;
        board[r][c] = 'R';
        for(const auto& dir : directions){
            dfs(r+dir.first, c+dir.second, board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int c = 0; c < COLS; ++c){
            if(board[0][c] == 'O') dfs(0, c, board);
            if(board[ROWS - 1][c] == 'O') dfs(ROWS - 1, c, board);
        }

        for(int r = 1; r < ROWS - 1; ++r){
            if(board[r][0] == 'O') dfs(r, 0, board);
            if(board[r][COLS - 1] == 'O') dfs(r, COLS - 1, board);
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(board[r][c] == 'O') board[r][c] = 'X';
                if(board[r][c] == 'R') board[r][c] = 'O';
            }
        }
    }
};
