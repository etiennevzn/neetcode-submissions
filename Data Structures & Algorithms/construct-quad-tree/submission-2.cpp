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
        bool allSame = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[r+i][c+j] != grid[r][c]){
                    allSame = false;
                    break;
                }
            }
        }

        if(allSame) return new Node(static_cast<bool>(grid[r][c]), true);

        Node* root = new Node(grid[r][c], false);
        root->topLeft = dfs(grid, n/2, r, c);
        root->topRight = dfs(grid, n/2, r, c+(n/2));
        root->bottomLeft = dfs(grid, n/2, r+(n/2), c);
        root->bottomRight = dfs(grid, n/2, r+(n/2), c+(n/2));

        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};