class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;
        vector<vector<int>> dp(stones.size() + 1, vector<int>(stoneSum + 1, 0));
        for(int i = 0; i <= stoneSum; ++i){
            dp[stones.size()][i] = abs(i - (stoneSum - i));
        }

        for(int i = stones.size() - 1; i >= 0; --i){
            for(int j = 0; j <= stoneSum; ++j){
                if(j + stones[i] <= stoneSum) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + stones[i]]);
                else break;
            }
        }

        return dp[0][0];
    }
};