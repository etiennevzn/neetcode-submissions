class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 0;

        vector<int> prevRow(COLS + 1, 0);

        for(int r = ROWS - 1; r >= 0; --r){
            vector<int> nextRow(COLS + 1, 0);
            for(int c = COLS - 1; c >= 0; --c){
                if(matrix[r][c] == '1'){
                    nextRow[c] = 1 + min(prevRow[c], min(nextRow[c + 1], prevRow[c  + 1]));
                    res = max(res, nextRow[c]);
                }
            }
            prevRow = nextRow;
        }

        return res * res;
    }
};