class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    int dfs(int row, int n){
        if(row == n) return 1;

        int res = 0;
        
        for(int col = 0; col < n; ++col){
            if(cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue;
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            res += dfs(row + 1, n);

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }

        return res;
    }
public:
    int totalNQueens(int n) {
        return dfs(0, n);
    }
};