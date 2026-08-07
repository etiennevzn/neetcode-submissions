class Solution {
    vector<vector<int>> memo;
    int dfs(int i, int cur, int target, vector<int>& stones){
        if(cur == target) return cur;
        if(cur > target) return 0;
        if(memo[i][cur] != -1) return memo[i][cur];

        int res = cur;
        for(int j = i; j < stones.size(); ++j){
            res = max(res, dfs(j + 1, cur + stones[j], target, stones));
        }

        return memo[i][cur] = res;
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        int target = s / 2;
        memo.resize(stones.size() + 1, vector<int>(target, -1));
        int pileSize = dfs(0, 0, target, stones);
        return abs(pileSize - (s - pileSize));
    }
};