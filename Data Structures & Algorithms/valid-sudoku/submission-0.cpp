class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(board.size());
        vector<unordered_set<char>> cols(board[0].size());
        vector<unordered_set<char>> squares(9);

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                char curElem = board[i][j];
                if(curElem == '.') continue;
                
                if(rows[i].count(curElem) || cols[j].count(curElem)
                    || squares[(i/3)*3+(j/3)].count(curElem)) return false;

                rows[i].insert(curElem);
                cols[j].insert(curElem);
                squares[(i/3)*3+(j/3)].insert(curElem);
            }
        }

        return true;
    }
};
