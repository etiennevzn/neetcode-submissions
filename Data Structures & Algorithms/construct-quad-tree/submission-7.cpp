/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* dfs(const vector<vector<int>>& grid, int n, int r, int c){
        if(n == 1) return new Node(static_cast<bool>(grid[r][c]), true);

        Node* topLeft = dfs(grid, n/2, r, c);
        Node* topRight = dfs(grid, n/2, r, c+(n/2));
        Node* bottomLeft = dfs(grid, n/2, r+(n/2), c);
        Node* bottomRight = dfs(grid, n/2, r+(n/2), c+(n/2));
        
        if(topLeft->isLeaf && topRight->isLeaf && bottomRight->isLeaf
            && bottomLeft->isLeaf && topLeft->val == topRight->val
            && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val){
                return topLeft;
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};