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
        Node* ptr1 = p, *ptr2 = q;

        while(ptr1 != ptr2){
            ptr1 = ptr1->parent;
            ptr2 = ptr2->parent;
            if(!ptr1) ptr1 = q;
            if(!ptr2) ptr2 = p;
        }

        return ptr1;
    }
};