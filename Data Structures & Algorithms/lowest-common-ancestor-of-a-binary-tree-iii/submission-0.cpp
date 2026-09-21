/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> pathP, pathQ;
        Node* cur = p;
        while(cur){
            pathP.insert(cur);
            cur = cur->parent;
        }

        cur = q;
        while(cur){
            if(pathP.count(cur)) return cur;
            cur = cur->parent;
        }

        return nullptr;
    }
};