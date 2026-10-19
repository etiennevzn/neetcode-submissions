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
        vector<int> visited(n*n + 1, false);

        cells.push(1);
        visited[1] = true;

        while(!cells.empty()){
            for(int i = cells.size(); i > 0; --i){
                int cur = cells.front();
                cells.pop();

                if(cur == n*n) return diceRolls;

                for(int next = cur + 1; next <= min(cur + 6, n*n); ++next){
                    int final = next;
                    auto [rnext, cnext] = getCoords(next, n);
                    if(board[rnext][cnext] != -1) final = board[rnext][cnext];

                    if(visited[final]) continue;

                    cells.push(final);
                    visited[final] = true;
                }
            }

            diceRolls++;
        }

        return -1;
    }
};