class Solution {
private:
    vector<vector<int>> memo;

    bool backtrack(int mask, int curSide, int lenSide, int numSides, const vector<int>& matchsticks){
        if(numSides == 4) return true;
        if(memo[mask][numSides] != -1) return memo[mask][numSides];
        if(curSide && lenSide && curSide == lenSide) return memo[mask][numSides] = backtrack(mask, 0, lenSide, numSides + 1, matchsticks);

        for(int j = 0; j < matchsticks.size(); ++j){
            if(mask & (1 << j)) continue;
            mask |= (1 << j);
            if(curSide + matchsticks[j] <= lenSide){
                if(backtrack(mask, curSide + matchsticks[j], lenSide, numSides, matchsticks)) return memo[mask][numSides] = true;
            }   
            mask &= ~(1 << j);
        }

        return memo[mask][numSides] = false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4) return false;
        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        if(matchsticks[0] > target) return false;
        memo.resize((1 << matchsticks.size()), vector<int>(4, -1));
        return backtrack(0, 0, target, 0, matchsticks);
    }
};