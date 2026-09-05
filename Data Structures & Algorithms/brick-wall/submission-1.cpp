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

        int maxGaps = 0;
        for(const auto& [line, num] : lines){
            maxGaps = max(num, maxGaps);
        }

        return wall.size() - maxGaps;
    }
};