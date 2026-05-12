class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curSum = 0;

        for(int num : nums){
            curSum += num;
            maxi = max(maxi, curSum);
            if(curSum < 0) curSum = 0;
        }
        return maxi;
    }
};
