class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        for(int i = 0; i < n; ++i){
            int slot = m - 1;
            for(int j = m - 1; j >= 0; --j){
                if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j], boxGrid[i][slot--]);
                }else if(boxGrid[i][j] == '*'){
                    slot = j - 1;
                }
            }
        }

        vector<vector<char>> res(m, vector<char>(n));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                res[j][n - i - 1] = boxGrid[i][j];
            }
        }

        return res;
    }
};