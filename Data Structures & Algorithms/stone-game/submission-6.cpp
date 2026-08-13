class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> line(n + 1, 0);
        for(int begin = n - 1; begin >= 0; --begin){
            vector<int> newLine(n + 1, 0);
            for(int end = begin; end < n; ++end){
                if(begin == end){
                    newLine[end] = piles[begin];
                    continue;
                }
                int b = piles[begin] - line[end];
                int e = piles[end] - newLine[end - 1];
                newLine[end] = max(b, e);
            }
            line = newLine;
        }
        return line[n - 1] > 0;
    }
};