class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));

        for(int i = 0; i < n; ++i){
            int slot = m - 1;
            for(int j = m - 1; j >= 0; --j){
                if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j], res[slot][n - i - 1]);
                    slot--;
                }else if(boxGrid[i][j] == '*'){
                    res[j][n - i - 1] = boxGrid[i][j];
                    slot = j - 1;
                }else{
                    res[j][n - i - 1] = boxGrid[i][j];
                }
            }
        }

        return res;
    }
};