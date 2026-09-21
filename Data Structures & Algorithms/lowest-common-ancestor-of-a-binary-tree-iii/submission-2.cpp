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
        unordered_set<Node*> pathP;
        while(p){
            pathP.insert(p);
            p = p->parent;
        }

        while(q){
            if(pathP.count(q)) return q;
            q = q->parent;
        }

        return nullptr;
    }
};