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
            tuple<TreeNode*, int, int> curNode = q.front();
            q.pop();

            TreeNode* node = get<0>(curNode);
            int minVal = get<1>(curNode);
            int maxVal = get<2>(curNode);

            if(node->val <= minVal || node->val >= maxVal) return false;
            if(node->left) q.push({node->left, minVal, node->val});
            if(node->right) q.push({node->right, node->val, maxVal});
        }

        return true;
    }
};
