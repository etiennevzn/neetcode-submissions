class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int curSum = 0;
        vector<int> countSub(nums.size() + 1, 0);
        countSub[0] = 1;

        int res = 0;
        for(int num : nums){
            curSum += num;
            if(curSum - goal >= 0) res += countSub[curSum - goal];
            countSub[curSum]++;
        }

        return res;
    }
};