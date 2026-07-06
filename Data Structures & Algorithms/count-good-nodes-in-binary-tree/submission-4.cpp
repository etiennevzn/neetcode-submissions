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
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -101});

        while(!q.empty()){
            auto [cur, maxVal] = q.front();
            q.pop();

            if(cur->val >= maxVal) res++;

            if(cur->left) q.push({cur->left, max(maxVal, cur->val)});
            if(cur->right) q.push({cur->right, max(maxVal, cur->val)});
        }
        
        return res;
    }
};
