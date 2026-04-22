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
    unordered_map<int,int> indices;
    int rootIndex = 0;

    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l > r) return nullptr;

        int midIndex = indices[preorder[rootIndex]];
        TreeNode* root = new TreeNode(preorder[rootIndex++]);

        root->left = dfs(preorder, l, midIndex-1);
        root->right = dfs(preorder, midIndex+1, r);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            indices[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size()-1);
    }
};
