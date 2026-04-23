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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        string res;

        while(!nodeQueue.empty()){
            TreeNode* curNode = nodeQueue.front();
            nodeQueue.pop();

            if(curNode){
                res += to_string(curNode->val) + ",";
                nodeQueue.push(curNode->left);
                nodeQueue.push(curNode->right);
            }else{
                res += "N,";
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if(val == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(getline(ss, val, ',')){
            TreeNode* curNode = nodeQueue.front();
            nodeQueue.pop();

            if(val != "N"){
                curNode->left = new TreeNode(stoi(val));
                nodeQueue.push(curNode->left);
            }

            getline(ss, val, ',');
            if(val != "N"){
                curNode->right = new TreeNode(stoi(val));
                nodeQueue.push(curNode->right);
            }
        }

        return root;
    }
};
