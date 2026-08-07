class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;
        unordered_set<int> dp = {0};
        unordered_set<int> newDp;

        for(int stone : stones){
            newDp = dp;
            for(int sum : dp){
                if(sum + stone == target) return stoneSum - 2 * target;
                if(sum + stone < target) newDp.insert(sum + stone);
            }
            dp = newDp;
        }

        int maxVal = 0;
        for(int sum : dp){
            maxVal = max(maxVal, sum);
        }

        return stoneSum - 2 * maxVal;
    }
};