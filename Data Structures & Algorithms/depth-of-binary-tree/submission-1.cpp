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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*,int>> nodeStack;
        int maxDepth = 1;
        nodeStack.push({root,1});

        while(!nodeStack.empty()){
            pair<TreeNode*,int> curNode = nodeStack.top();
            maxDepth = max(maxDepth, curNode.second);
            nodeStack.pop();

            if(curNode.first->right) nodeStack.push({curNode.first->right,curNode.second+1});
            if(curNode.first->left) nodeStack.push({curNode.first->left,curNode.second+1});
        }

        return maxDepth;
    }
};
