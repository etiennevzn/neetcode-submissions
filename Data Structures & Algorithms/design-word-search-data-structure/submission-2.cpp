struct TrieNode{
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string word, int startIdx, TrieNode* root){
        TrieNode* curNode = root;
        for(int i = startIdx; i < word.size(); ++i){
            char c = word[i];
            if(c == '.'){
                for(auto child : curNode->children){
                    if(child && dfs(word, i+1, child)) return true;
                }
                return false;
            }else{
                int idx = c - 'a';
                if(!curNode->children[idx]){
                    return false;
                }
                curNode = curNode->children[idx];
            }
        }
        return curNode->isEnd;
    }
public:
    WordDictionary() : root(new TrieNode()){};
    
    void addWord(string word) {
        TrieNode* curNode = root;
        for(const char& c : word){
            int idx = c - 'a';
            if(!curNode->children[idx]){
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
