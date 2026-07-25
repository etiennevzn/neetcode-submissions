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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        
        if(root->val == key){
            if(!root->right) return root->left;
            if(!root->left) return root->right;

            TreeNode* cur = root->right;
            while(cur->left){
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteNode(root->right, cur->val);
        }

        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};