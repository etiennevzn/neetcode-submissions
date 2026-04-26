/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> nodesList;

    void dfs(Node* node){
        if(nodesList.count(node)) return;

        Node* clone = new Node(node->val);
        nodesList[node] = clone;

        for(Node* neighbor : node->neighbors){
            dfs(neighbor);
            nodesList[node]->neighbors.push_back(nodesList[neighbor]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        dfs(node);
        return nodesList[node];
    }
};
