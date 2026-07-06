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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);

        while(!q.empty()){
            TreeNode* rightNode;
            int qLen = q.size();

            for(int i = 0; i < qLen; ++i){
                TreeNode* cur = q.front();
                q.pop();
                rightNode = cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            res.push_back(rightNode->val);
        }

        return res;
    }
};
