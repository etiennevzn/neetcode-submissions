class TrieNode{
public : 
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : isEnd(false), children(26, nullptr){}

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
    vector<vector<bool>> visited;
    unordered_set<string> res;

    void dfs(vector<vector<char>>& board, string& word, int r, int c, TrieNode* node){
        if(r >= ROWS || r < 0 || c < 0 || c >= COLS || visited[r][c]) return;
        char ch = board[r][c];
        int idx = ch - 'a';
        if(!node->children[idx]) return;

        visited[r][c] = true;
        node = node->children[idx];
        word.push_back(ch);
        if(node->isEnd){
            res.insert(word);
        }

        dfs(board, word, r, c + 1, node);
        dfs(board, word, r, c - 1, node);
        dfs(board, word, r + 1, c, node);
        dfs(board, word, r - 1, c, node);

        word.pop_back();
        visited[r][c] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        TrieNode* root = new TrieNode();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for(const string& word : words){
            root->addWord(word);
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                string word = "";
                dfs(board, word, r, c, root);
            }
        }
        
        vector<string> final(res.begin(), res.end());
        return final;
    }
};
