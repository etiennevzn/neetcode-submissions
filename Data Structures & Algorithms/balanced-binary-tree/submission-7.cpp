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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        unordered_map<TreeNode*, pair<int,bool>> mp;
        stack<TreeNode*> s;
        mp[nullptr] = {0, true};
        s.push(root);

        while(!s.empty()){
            TreeNode* cur = s.top();
            if(cur->left && !mp.count(cur->left)){
                s.push(cur->left);
            }else if(cur->right && !mp.count(cur->right)){
                s.push(cur->right);
            }else{
                s.pop();
                auto [rightHeight, rightBalanced] = mp[cur->right];
                auto [leftHeight, leftBalanced] = mp[cur->left];

                int height = 1 + max(rightHeight, leftHeight);
                int balanced = ((rightBalanced && leftBalanced) && abs(rightHeight - leftHeight) <= 1);
                if(!balanced) return false;
                mp[cur] = {height, balanced};
            }
        }

        return true;
    }
};
