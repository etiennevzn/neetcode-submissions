class NumMatrix {
private:    
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        prefix.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        for(int r = 0; r < matrix.size(); ++r){
            int cur = 0;
            for(int c = 0; c < matrix[0].size(); ++c){
                cur += matrix[r][c];
                prefix[r + 1][c + 1] = cur + prefix[r][c + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = prefix[row2 + 1][col2 + 1];
        int above = prefix[row1][col2 + 1];
        int left = prefix[row2 + 1][col1];
        int topLeft = prefix[row1][col1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */