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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        int height = 0;
        q.push(root);

        while(!q.empty()){
            for(int i = q.size(); i > 0; --i){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            height++;
        }

        q.push(root);
        int curHeight = 0, numNodes = 0;
        bool leftMost = false;
        while(!q.empty()){
            curHeight++;
            int qSize = q.size();
            if(numNodes != 0 && curHeight < height && qSize != numNodes * 2) return false;

            numNodes *= 2;
            for(int i = qSize; i > 0; --i){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left){
                    if(leftMost) return false;
                    q.push(cur->left);
                }else{
                    leftMost = true;
                }

                if(cur->right){
                    if(leftMost) return false;
                    q.push(cur->right);
                }
            }
        }

        return true;
    }
};