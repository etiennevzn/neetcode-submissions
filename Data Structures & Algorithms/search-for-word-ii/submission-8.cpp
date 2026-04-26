class TrieNode{
public : 
    int idx;
    vector<TrieNode*> children;
    int refs;

    TrieNode() : idx(-1), children(26, nullptr), refs(0){}

    void addWord(const string& word, int i){
        TrieNode* cur = this;
        cur->refs++;
        for(char c : word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new TrieNode();
            } 
            cur = cur->children[idx];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
private:
    int ROWS;
    int COLS;
    vector<string> res;

    void dfs(vector<vector<char>>& board, vector<string>& words, int r, int c, TrieNode* node){
        if(r >= ROWS || r < 0 || c < 0 || c >= COLS || board[r][c] == '#') return;
        char ch = board[r][c];
        int idx = ch - 'a';
        if(!node->children[idx]) return;

        char temp = board[r][c];
        board[r][c] = '#';
        TrieNode* prev = node;
        node = node->children[idx];

        if(node->idx != -1){
            res.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if(!node->refs){
                prev->children[idx] = nullptr;
                node = nullptr;
                board[r][c] = temp;
                return;
            }
        }

        dfs(board, words, r, c + 1, node);
        dfs(board, words, r, c - 1, node);
        dfs(board, words, r + 1, c, node);
        dfs(board, words, r - 1, c, node);

        board[r][c] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); ++i){
            root->addWord(words[i], i);
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                dfs(board, words, r, c, root);
            }
        }
        
        return res;
    }
};
