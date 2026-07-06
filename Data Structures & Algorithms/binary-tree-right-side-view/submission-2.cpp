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
        if(!root->right && !root->left) return {root->val};
        
        queue<pair<TreeNode*, int>> q;
        vector<int> res;
        pair<int, int> prevLevel = {root->val, 0};
        if(root->left) q.push({root->left,1});
        if(root->right) q.push({root->right,1});

        while(!q.empty()){
            auto [cur, curLevel] = q.front();
            q.pop();

            if(curLevel != prevLevel.second){
                res.push_back(prevLevel.first);
            }
            if(q.empty() && !cur->left && !cur->right){
                res.push_back(cur->val);
            }

            if(cur->left) q.push({cur->left, curLevel+1});
            if(cur->right) q.push({cur->right, curLevel+1});
            prevLevel = {cur->val, curLevel};
        }

        return res;
    }
};
