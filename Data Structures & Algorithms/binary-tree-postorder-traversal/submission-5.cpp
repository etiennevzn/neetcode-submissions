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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root); 
        unordered_set<TreeNode*> visited;
        vector<int> res;

        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            if(!cur) continue;
            if(!visited.count(cur)){
                visited.insert(cur);
                s.push(cur);
                s.push(cur->right);
                s.push(cur->left);
            }else{
                res.push_back(cur->val);
            }
        }
        return res;
    }
};