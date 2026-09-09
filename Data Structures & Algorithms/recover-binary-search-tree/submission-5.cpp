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

        bool set1 = false;
        TreeNode* err1, *err2;
        int n = inorder.size();
        for(int i = 0; i < n - 1; ++i){
            if(inorder[i]->val > inorder[i + 1]->val){
                if(!set1){
                    err1 = inorder[i];
                    set1 = true;
                }

                err2 = inorder[i + 1];
            }
        }

        swap(err1->val, err2->val);
    }
};