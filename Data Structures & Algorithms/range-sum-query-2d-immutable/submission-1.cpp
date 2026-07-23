class NumMatrix {
private:    
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        prefix.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int r = 0; r < matrix.size(); ++r){
            int cur = 0;
            for(int c = 0; c < matrix[0].size(); ++c){
                cur += matrix[r][c];
                prefix[r][c] = cur;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int r = row1; r <= row2; ++r){
            res += prefix[r][col2];
            if(col1 - 1 >= 0) res -= prefix[r][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */