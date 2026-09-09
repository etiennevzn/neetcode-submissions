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
    vector<int> inorder;
    void traversal(TreeNode* root){
        if(!root) return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }

    void correct(TreeNode* root, int err1, int err2){
        if(!root) return;
        if(root->val == err1){
            root->val = err2;
        }else if(root->val == err2){
            root->val = err1;
        }
    
        correct(root->left, err1, err2);
        correct(root->right, err1, err2);
    }
public:
    void recoverTree(TreeNode* root) {
        traversal(root);
        bool set1 = false;
        int err1 = 0, err2 = 0;
        int n = inorder.size();
        for(int i = 0; i < n - 1; ++i){
            if(inorder[i] > inorder[i + 1]){
                if(!set1) err1 = inorder[i];
                err2 = inorder[i + 1];
                set1 = true;
            }
        }
        correct(root, err1, err2);
    }
};