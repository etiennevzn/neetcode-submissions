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
    TreeNode* dfs(TreeNode* node, int target){
        if(!node) return nullptr;
        
        node->left = dfs(node->left, target);
        node->right = dfs(node->right, target);
        
        if(!node->right && !node->left && node->val == target){
            delete node;
            return nullptr;
        }

        return node;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};