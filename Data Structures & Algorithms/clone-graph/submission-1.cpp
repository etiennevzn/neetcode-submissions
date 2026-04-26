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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> nodesList;

        nodesList[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(Node* neighbor : cur->neighbors){
                if(!nodesList.count(neighbor)){
                    q.push(neighbor);
                    Node* cloneN = new Node(neighbor->val);
                    nodesList[neighbor] = cloneN;
                }
                nodesList[cur]->neighbors.push_back(nodesList[neighbor]);
            }
        }

        return nodesList[node];
    }
};
