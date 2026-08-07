class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> line(stoneSum + 1, 0);  
        for(int i = 0; i <= stoneSum; ++i){
            line[i] = abs(i - (stoneSum - i));
        }

        for(int i = stones.size() - 1; i >= 0; --i){
            vector<int> newLine(stoneSum + 1, 0);
            for(int j = 0; j <= stoneSum; ++j){
                if(j + stones[i] <= stoneSum) newLine[j] = min(line[j], line[j + stones[i]]);
                else break;
            }
            line = newLine;
        }

        return line[0];
    }
};