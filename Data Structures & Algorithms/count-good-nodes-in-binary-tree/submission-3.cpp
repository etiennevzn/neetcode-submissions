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
    int res = 0;

    void dfs(TreeNode* root, int highest){
        if(!root) return;
        if(root->val >= highest){
            res++;
            highest = root->val;
        }

        dfs(root->left, highest);
        dfs(root->right, highest);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};
