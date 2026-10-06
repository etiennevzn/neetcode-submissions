class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original == color) return image;

        int ROWS = image.size(), COLS = image[0].size();
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> qCoords;
        qCoords.emplace(sr, sc);
        image[sr][sc] = color;

        while(!qCoords.empty()){
            auto [r, c] = qCoords.front();
            qCoords.pop();

            for(const auto& dir : dirs){
                int nr = r + dir.first, nc = c + dir.second;
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
                if(image[nr][nc] == original){
                    qCoords.emplace(nr, nc);
                    image[nr][nc] = color;
                }
            }
        }

        return image;
    }
};