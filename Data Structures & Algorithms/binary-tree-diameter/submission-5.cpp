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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int,int>> mp;
        stack<TreeNode*> s;
        mp[nullptr] = {0,0};
        s.push(root);

        while(!s.empty()){
            TreeNode* cur = s.top();

            if(cur->left && !mp.count(cur->left)){
                s.push(cur->left);
            }else if(cur->right && !mp.count(cur->right)){
                s.push(cur->right);
            }else{
                s.pop();
                int leftHeight = mp[cur->left].first;
                int rightHeight = mp[cur->right].first;
                int height = 1 + max(leftHeight, rightHeight);

                int leftDiameter = mp[cur->left].second;
                int rightDiameter = mp[cur->right].second;
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

                mp[cur] = {height, diameter};
            }
        }

        return mp[root].second;
    }
};
