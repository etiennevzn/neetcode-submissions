class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> rows, cols, squares;

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                char curElem = board[i][j];
                
                if(curElem == '.') continue;
                int pos = curElem - '0';

                if((rows[i] >> pos) & 1 || (cols[j] >> pos) & 1
                    || (squares[(i/3)*3+(j/3)] >> pos) & 1) return false;

                rows[i] |= (1 << pos);
                cols[j] |= (1 << pos);
                squares[(i/3)*3+(j/3)] |= (1 << pos);
            }
        }

        return true;
    }
};
