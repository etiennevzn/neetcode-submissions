class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(100);
        for(size_t i = 0; i < 100; ++i){
            glasses[i].resize(i + 1);
        }

        glasses[0][0] = poured;
        for(int r = 0; r < query_row; ++r){
            for(int glass = 0; glass <= r; ++glass){
                double overflow = max(0.0, glasses[r][glass] - 1.0);

                glasses[r + 1][glass] += overflow / 2.0;
                glasses[r + 1][glass + 1] += overflow / 2.0;
                glasses[r][glass] -= overflow; 
            }
        }

        return min(1.0, glasses[query_row][query_glass]);
    }
};
