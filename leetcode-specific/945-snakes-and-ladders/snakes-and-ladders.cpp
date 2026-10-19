class Solution {
private:
    pair<int,int> getCoords(int cell, int n){
        int rnext = n - 1 - (cell - 1) / n;
        int cnext = (cell - 1) % n;
        if ((n - 1 - rnext) % 2 == 1){
            cnext = n - 1 - cnext;
        }

        return {rnext, cnext};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int diceRolls = 0;
        queue<int> cells;
        vector<bool> visited(n*n + 1, false);

        cells.push(1);
        visited[1] = true;

        while(!cells.empty()){
            for(int i = cells.size(); i > 0; --i){
                int cur = cells.front();
                cells.pop();

                for(int next = cur + 1; next <= min(cur + 6, n*n); ++next){
                    int dest = next;
                    auto [rnext, cnext] = getCoords(next, n);
                    if(board[rnext][cnext] != -1) dest = board[rnext][cnext];

                    if(visited[dest]) continue;

                    if(dest == n*n) return diceRolls + 1;
                    cells.push(dest);
                    visited[dest] = true;
                }
            }

            diceRolls++;
        }

        return -1;
    }
};