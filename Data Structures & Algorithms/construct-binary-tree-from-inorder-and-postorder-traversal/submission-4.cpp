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
    TreeNode* build(int iStart, int iEnd, int& pIdx, const vector<int>& inorder, const vector<int>& postorder, const unordered_map<int,int>& inIdx){
        if(iStart > iEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[pIdx--]);
        if(iStart == iEnd) return root;

        int j = inIdx.at(root->val);
        root->right = build(j + 1, iEnd, pIdx, inorder, postorder, inIdx); 
        root->left = build(iStart, j - 1, pIdx, inorder, postorder, inIdx);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inIdx;
        for(int i = 0; i < inorder.size(); ++i){
            inIdx[inorder[i]] = i;
        }
        int iEnd = inorder.size() - 1, pIdx = postorder.size() - 1;
        return build(0, iEnd, pIdx, inorder, postorder, inIdx);
    }
};