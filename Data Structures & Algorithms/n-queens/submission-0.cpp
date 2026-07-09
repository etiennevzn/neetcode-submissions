class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> pos_diags;
    unordered_set<int> neg_diags;
    vector<vector<string>> res;

    void dfs(vector<string>& cur, int row, int n){
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }
        for(int col = 0; col < n; ++col){
            if(!cols.count(col) && !pos_diags.count(row - col) && !neg_diags.count(row + col)){
                string line = "";
                for(int i = 0; i < col; ++i) line.push_back('.');
                line.push_back('Q');
                for(int i = col + 1; i < n; ++i) line.push_back('.');

                cols.insert(col);
                pos_diags.insert(row - col);
                neg_diags.insert(row + col);

                cur.push_back(line);
                dfs(cur, row + 1, n);
                cur.pop_back();

                cols.erase(col);
                pos_diags.erase(row - col);
                neg_diags.erase(row + col);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
       res.clear();
       vector<string> cur;
       dfs(cur, 0, n);
       return res; 
    }
};
