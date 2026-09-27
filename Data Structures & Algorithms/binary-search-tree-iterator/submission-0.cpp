/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    int i;
    vector<int> inorder;

    void traversal(TreeNode* node){
        if(!node) return;
        traversal(node->left);
        inorder.push_back(node->val);
        traversal(node->right);
    }
public:
    BSTIterator(TreeNode* root) : i(-1) {
        traversal(root);
    }
    
    int next() {
        return inorder[++i];
    }
    
    bool hasNext() {
        return !(i == inorder.size() - 1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */