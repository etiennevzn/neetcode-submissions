class Solution {
private:
    int ROWS; 
    int COLS;
    vector<vector<bool>> visited;

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        } 

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS) return false;
        if(board[r][c] != word[i]) return false;
        if(visited[r][c]) return false;

        visited[r][c] = true;

        bool res = backtrack(board, word, r + 1, c, i + 1) ||
                   backtrack(board, word, r - 1, c, i + 1) ||
                   backtrack(board, word, r, c + 1, i + 1) ||
                   backtrack(board, word, r, c - 1, i + 1);
        
        visited[r][c] = false;

        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r < ROWS; ++r){
            vector<bool> temp(COLS, false);
            visited.push_back(temp);
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; c++){
                if(backtrack(board, word, r, c, 0)) return true;
            }
        }

        return false;
    }
};
