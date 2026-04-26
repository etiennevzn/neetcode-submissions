class TrieNode{
public : 
    bool isEnd;
    vector<TrieNode*> children;
    int refs;

    TrieNode() : isEnd(false), children(26, nullptr), refs(0){}

    void addWord(const string& word){
        TrieNode* cur = this;
        for(char c : word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new TrieNode();
            } 
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
};

class Solution {
private:
    int ROWS;
    int COLS;
    vector<string> res;

    void dfs(vector<vector<char>>& board, string& word, int r, int c, TrieNode* node){
        if(r >= ROWS || r < 0 || c < 0 || c >= COLS || board[r][c] == '#') return;
        char ch = board[r][c];
        int idx = ch - 'a';
        if(!node->children[idx]) return;

        char temp = board[r][c];
        board[r][c] = '#';
        node = node->children[idx];
        word.push_back(ch);
        if(node->isEnd){
            res.push_back(word);
            node->isEnd = false;
        }

        dfs(board, word, r, c + 1, node);
        dfs(board, word, r, c - 1, node);
        dfs(board, word, r + 1, c, node);
        dfs(board, word, r - 1, c, node);

        word.pop_back();
        board[r][c] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        TrieNode* root = new TrieNode();

        for(const string& word : words){
            root->addWord(word);
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                string word = "";
                dfs(board, word, r, c, root);
            }
        }
        
        return res;
    }
};
