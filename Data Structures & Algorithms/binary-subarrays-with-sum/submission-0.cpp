class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int curSum = 0;
        unordered_map<int,int> countSub;
        countSub[0] = 1;

        int res = 0;
        for(int num : nums){
            curSum += num;
            if(countSub.count(curSum - goal)) res += countSub[curSum - goal];
            countSub[curSum]++;
        }

        return res;
    }
};