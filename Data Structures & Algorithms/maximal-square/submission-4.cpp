class Solution {
private: 
    int ROWS, COLS;
    bool checkSquare(int size, int r, int c, const vector<vector<char>>& matrix){
        for(int i = r; i < r + size; ++i){
            for(int j = c; j < c + size; ++j){
                if(i >= ROWS || j >= COLS || matrix[i][j] != '1') return false;
            }
        }
        return true;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 0;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(matrix[r][c] == '1'){
                    int size = 1;
                    while(checkSquare(size, r, c, matrix)) size++;
                    res = max(res, size - 1);
                }
            }
        }

        return res == 1 ? res : res * res;
    }
};