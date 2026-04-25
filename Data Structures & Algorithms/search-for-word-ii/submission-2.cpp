class Solution {
private:
    int ROWS;
    int COLS;

    bool findWord(vector<vector<char>>& board, string& word, int r, int c, int i){
        if(i == word.size()) return true;
        if(r >= ROWS || r < 0 || c < 0 || c >= COLS || board[r][c] != word[i]) return false;

        board[r][c] = '#';

        bool res = (findWord(board, word, r, c + 1, i + 1)
            || findWord(board, word, r, c - 1, i + 1)
            || findWord(board, word, r + 1, c, i + 1)
            || findWord(board, word, r - 1, c, i + 1)
        );

        board[r][c] = word[i];
        return res;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        ROWS = board.size();
        COLS = board[0].size();

        for(string& word : words){
            for(int r = 0; r < ROWS; ++r){
                for(int c = 0; c < COLS; ++c){
                    if(findWord(board, word, r, c, 0)){
                        res.insert(word);
                    }
                }
            }
        }
        vector<string> final(res.begin(), res.end());
        return final;
    }
};
