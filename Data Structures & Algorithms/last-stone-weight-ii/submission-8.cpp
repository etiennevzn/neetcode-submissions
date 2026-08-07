class Solution {
    vector<vector<int>> memo;
    int dfs(int i, int cur, int target, int stoneSum, vector<int>& stones){
        if(cur >= target || i == stones.size()) return abs(cur - (stoneSum - cur));
        if(memo[i][cur] != -1) return memo[i][cur];

        return memo[i][cur] = min(dfs(i + 1, cur, target, stoneSum, stones), dfs(i + 1, cur + stones[i], target, stoneSum, stones));
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;
        memo.resize(stones.size(), vector<int>(target, -1));
        return dfs(0, 0, target, stoneSum, stones);
    }
};