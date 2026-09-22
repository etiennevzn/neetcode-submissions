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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        res.push_back({root->val});

        while(!q.empty()){
            vector<int> cur;
            for(int i = q.size(); i > 0; --i){
                TreeNode* curNode = q.front();
                q.pop();
                if(curNode->left){
                    q.push(curNode->left);
                    cur.push_back(curNode->left->val);
                }

                if(curNode->right){
                    q.push(curNode->right);
                    cur.push_back(curNode->right->val);
                }
            }
            
            if(!cur.empty()) res.push_back(cur);
        }

        for(int i = 0; i < res.size(); ++i){
            if(i % 2) reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};