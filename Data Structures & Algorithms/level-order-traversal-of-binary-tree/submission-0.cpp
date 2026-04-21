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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            int lvlSize = nodeQueue.size();
            vector<int> lvlValues;
            for(int i = 0; i < lvlSize; ++i){
                TreeNode* curNode = nodeQueue.front();
                nodeQueue.pop();
                lvlValues.push_back(curNode->val);
                if(curNode->left) nodeQueue.push(curNode->left);
                if(curNode->right) nodeQueue.push(curNode->right);
            }
            res.push_back(lvlValues);
        }

        return res;
    }
};
