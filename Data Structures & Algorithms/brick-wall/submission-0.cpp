class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> lines;
        
        for(const vector<int>& row : wall){
            int line = 0;
            for(int brick : row){
                line += brick;
                lines[line]++;
            }
        }

        int sizeWall = accumulate(wall[0].begin(), wall[0].end(), 0);
        lines[sizeWall] = 0;

        int maxLine = sizeWall;
        for(const auto& [line, num] : lines){
            if(num > lines[maxLine]) maxLine = line;
        }

        return wall.size() - lines[maxLine];
    }
};