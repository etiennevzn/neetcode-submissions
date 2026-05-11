class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curSum = INT_MIN;

        for(int i = nums.size(); i >= 0; --i){
            curSum += nums[i];
            maxi = max(maxi, curSum);
            if(curSum < 0) curSum = 0;
        }
        return maxi;
    }
};
