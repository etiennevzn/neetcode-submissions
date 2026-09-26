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
    TreeNode* build(int iStart, int iEnd, int& pIdx, const vector<int>& inorder, const vector<int>& postorder){
        if(iStart > iEnd) return nullptr;
        int val = postorder[pIdx--];
        TreeNode* root = new TreeNode(val);
        if(iStart == iEnd) return root;

        int j = iStart;
        while(j < inorder.size() && inorder[j] != val) j++;
        root->right = build(j + 1, iEnd, pIdx, inorder, postorder); 
        root->left = build(iStart, j - 1, pIdx, inorder, postorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int iEnd = inorder.size() - 1, pIdx = postorder.size() - 1;
        return build(0, iEnd, pIdx, inorder, postorder);
    }
};