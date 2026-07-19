class CountSquares {
private:
    unordered_map<int, unordered_map<int,int>> pCount;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        pCount[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int qX = point[0];
        int qY = point[1];
        for(const auto& [y, count1] : pCount[qX]){
            int side = qY - y;
            if(side == 0) continue;
            int x2 = qX + side;
            int x3 = qX - side;

            res += count1 * pCount[x2][qY] * pCount[x2][y];
            res += count1 * pCount[x3][qY] * pCount[x3][y];
        }

        return res;
    }
};
