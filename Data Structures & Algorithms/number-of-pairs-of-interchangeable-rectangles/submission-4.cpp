class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string,int> ratioCount;
        for(const auto& rectangle : rectangles){
            int w = rectangle[0], h = rectangle[1];
            int g = gcd(w , h);
            string ratio = to_string(w / g) + "/" + to_string(h / g);
            ratioCount[ratio]++;
        }

        long long res = 0;
        for(const auto& p : ratioCount){
            long long count = p.second;
            res += (count * (count - 1)) / 2;
        }

        return res;
    }
};
