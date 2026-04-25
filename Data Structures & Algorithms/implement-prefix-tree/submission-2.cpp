struct TreeNode{
    bool isEnd = false;
    unordered_map<char, TreeNode*> children;
};

class PrefixTree {
private:
    TreeNode* root;
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for(const char& c : word){
            if(!cur->children.count(c)){
                cur->children[c] = new TreeNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for(const char& c : word){
            if(!cur->children.count(c)){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(const char& c : prefix){
            if(!cur->children.count(c)){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
