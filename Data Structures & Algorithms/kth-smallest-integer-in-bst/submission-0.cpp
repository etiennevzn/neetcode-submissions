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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodeStack;
        int n = 0;
        TreeNode* curNode = root;


        while(curNode || !nodeStack.empty()){
            while(curNode){
                nodeStack.push(curNode);
                curNode = curNode->left;
            }

            curNode = nodeStack.top();
            nodeStack.pop();

            n++;
            if(n == k) return curNode->val;

            curNode = curNode->right;
        }

        return -1;
    }
};
