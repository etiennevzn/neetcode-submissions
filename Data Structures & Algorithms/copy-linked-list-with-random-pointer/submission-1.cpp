/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> nodeMap;
        nodeMap[nullptr] = nullptr;

        Node* cur = head;
        while(cur){
            if(nodeMap.find(cur) == nodeMap.end()){
                nodeMap[cur] = new Node(0);
            }
            nodeMap[cur]->val = cur->val;

            if(nodeMap.find(cur->next) == nodeMap.end()){
                nodeMap[cur->next] = new Node(0);
            }
            nodeMap[cur]->next = nodeMap[cur->next];

            if(nodeMap.find(cur->random) == nodeMap.end()){
                nodeMap[cur->random] = new Node(0);
            }
            nodeMap[cur]->random = nodeMap[cur->random];

            cur = cur->next;
        }
        return nodeMap[head];
    }
};
