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
        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 0;

        while(!queue.empty()){
            int lvlSize = queue.size();
            for(int i = 0; i<lvlSize; ++i){
                TreeNode* curNode = queue.front();
                queue.pop();
                if(curNode->right) queue.push(curNode->right);
                if(curNode->left) queue.push(curNode->left);
            }
            depth++;
        }

        return depth;
    }
};
