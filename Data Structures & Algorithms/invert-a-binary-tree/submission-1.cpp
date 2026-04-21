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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode* curNode = nodeStack.top();
            nodeStack.pop();
            std::swap(curNode->right, curNode->left);
            if(curNode->right) nodeStack.push(curNode->right);
            if(curNode->left) nodeStack.push(curNode->left);
        }

        return root;
    }
};
