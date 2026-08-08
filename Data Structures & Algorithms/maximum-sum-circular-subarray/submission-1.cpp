class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMin = 0, globalMin = INT_MAX;
        int curMax = 0, globalMax = INT_MIN;
        int numsSum = 0;

        for(int i = 0; i < nums.size(); ++i){
            numsSum += nums[i];
            curMin = min(curMin + nums[i], nums[i]);
            curMax = max(curMax + nums[i], nums[i]);
            globalMin = min(globalMin, curMin);
            globalMax = max(globalMax, curMax);
        }

        if(globalMax < 0) return globalMax;

        return max(globalMax, numsSum - globalMin);
    }
};