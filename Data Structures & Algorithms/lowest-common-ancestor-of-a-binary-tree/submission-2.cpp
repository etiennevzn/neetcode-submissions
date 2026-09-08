/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> ancestors;
    bool dfs(TreeNode* root, TreeNode* node){
        ancestors.push_back(root);

        if(root == node) return true;
        if(root->left && dfs(root->left, node)) return true;
        if(root->right && dfs(root->right, node)) return true;

        ancestors.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestors.clear();
        dfs(root, p);
        vector<TreeNode*> pAncestors = ancestors;
        ancestors.clear();
        dfs(root, q);
        unordered_set<TreeNode*> qAncestors = unordered_set<TreeNode*>(ancestors.begin(), ancestors.end());

        for(int i = pAncestors.size() - 1; i >= 0; --i){
            if(qAncestors.count(pAncestors[i])) return pAncestors[i];
        }

        return root;
    }
};