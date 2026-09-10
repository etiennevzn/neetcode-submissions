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
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int>& cur){
        cur.push_back(root->val);
        if(!root->left && !root->right){
            res.push_back(cur);
        }else{
            if(root->left) dfs(root->left, cur);    
            if(root->right) dfs(root->right, cur);
        }
        cur.pop_back();
    }

    int tabToInt(const vector<int>& nums){
        int result = 0;
        for(int num : nums){
            result *= 10;
            result += num;
        }
        return result;
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> cur;
        dfs(root,cur);
        int final = 0;
        for(const vector<int>& num : res){
            final += tabToInt(num);
        }
        return final;
    }
};