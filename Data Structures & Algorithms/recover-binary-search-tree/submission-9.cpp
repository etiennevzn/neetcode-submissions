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
class Solution {
private:
    void traversal(TreeNode* root, vector<TreeNode*>& inorder){
        if(!root) return;
        traversal(root->left, inorder);
        inorder.push_back(root);
        traversal(root->right, inorder);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        traversal(root, inorder);

        TreeNode* err1 = nullptr, *err2 = nullptr;
        for(int i = 0; i < inorder.size() - 1; ++i){
            if(inorder[i]->val > inorder[i + 1]->val){
                if(!err1) err1 = inorder[i];
                err2 = inorder[i + 1];
            }
        }

        swap(err1->val, err2->val);
    }
};