class Solution {
private:
    int cols = 0, diag1 = 0, diag2 = 0;

    int dfs(int row, int n){
        if(row == n) return 1;

        int res = 0;

        for(int col = 0; col < n; ++col){
            if(cols & (1 << col) || diag1 & (1 << (row - col + n)) || diag2 & (1 << row + col)) continue;

            cols |= (1 << col);
            diag1 |= (1 << (row - col + n));
            diag2 |= (1 << (row + col));

            res += dfs(row + 1, n);

            cols &= ~(1 << col);
            diag1 &= ~(1 << (row - col + n));
            diag2 &= ~(1 << row + col);
        }

        return res;
    }
public:
    int totalNQueens(int n) {
        return dfs(0, n);
    }
};