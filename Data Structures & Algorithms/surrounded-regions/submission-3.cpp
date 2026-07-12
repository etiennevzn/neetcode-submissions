class DSU {
private:
    vector<int> Parent, Size;
public :
    DSU(int n){
        Parent.resize(n+1);
        Size.resize(n+1);
        for(int i = 0; i < n+1; ++i){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node){
        if(Parent[node] != node){
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(Size[pu] >= Size[pv]){
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }else{
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        }
        return true;
    }

    bool connected(int u, int v){
        return find(u) == find(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        DSU dsu(ROWS*COLS+1);

        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(board[r][c] != 'O') continue;
                if(r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1){
                    dsu.unionNodes(ROWS * COLS, r*COLS + c);
                }else{
                    for(const auto& dir : directions){
                        int newr = r + dir[0], newc = c + dir[1];
                        if(board[newr][newc] == 'O') dsu.unionNodes(r * COLS + c, newr * COLS + newc);
                    }
                }
            }
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(!dsu.connected(ROWS * COLS, r * COLS + c)) board[r][c] = 'X';
            }
        }
    }
};
