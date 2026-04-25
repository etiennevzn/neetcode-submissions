struct TreeNode{
    bool isEnd;
    vector<TreeNode*> children;

    TreeNode() : isEnd(false), children(26, nullptr){}
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
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new TreeNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for(const char& c : word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(const char& c : prefix){
            int idx = c - 'a';
            if(!cur->children[idx]){
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};
