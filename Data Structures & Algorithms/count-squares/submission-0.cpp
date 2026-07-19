class CountSquares {
private:
    vector<vector<int>> pCount;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        pCount.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;

        for(const auto& p1 : pCount){
            if(p1[1] != point[1] || p1 == point) continue;
            for(const auto& p2 : pCount){
                if(p1[0] != p2[0] || p2 == point) continue;
                for(const auto& p3 : pCount){
                    if(p3[1] != p2[1] || p3[0] != point[0] || p3 == point) continue;
                    res++;
                }
            }
        }

        return res;
    }
};
