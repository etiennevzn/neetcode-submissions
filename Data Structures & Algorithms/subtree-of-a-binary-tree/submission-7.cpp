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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(sameTree(root, subRoot)) return true;
        return(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

private:
    bool sameTree(TreeNode* root1, TreeNode* root2){
        stack<pair<TreeNode*, TreeNode*>> stck;
        stck.push({root1,root2});

        while(!stck.empty()){
            auto [node1, node2] = stck.top();
            stck.pop();
            if(!node1 && !node2) continue;
            if(!node1 || !node2 || node1->val != node2->val) return false;
            stck.push({node1->right, node2->right});
            stck.push({node1->left, node2->left});
        }

        return true;
    }
};
