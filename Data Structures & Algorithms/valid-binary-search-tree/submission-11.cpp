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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;

        if(!root) return true;
        q.push({root, INT_MIN, INT_MAX});

        while(!q.empty()){
            auto [node, minVal, maxVal] = q.front();
            q.pop();

            if(node->val <= minVal || node->val >= maxVal) return false;
            if(node->left) q.push({node->left, minVal, node->val});
            if(node->right) q.push({node->right, node->val, maxVal});
        }

        return true;
    }
};
