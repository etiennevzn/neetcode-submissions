class Solution {
private: 
    int dfs(vector<int>& nums, int l, int r){
        if(l > r) return INT_MIN;

        int midIdx = (l+r) >> 1;
        int maxRight = 0, maxLeft = 0, curSum = 0;
        for(int i = midIdx - 1; i >= l; --i){
            curSum += nums[i];
            maxLeft = max(maxLeft, curSum);
        }
        curSum = 0;
        for(int i = midIdx + 1; i <= r; ++i){
            curSum += nums[i];
            maxRight = max(maxRight, curSum);
        }
        int maxMid = maxLeft + nums[midIdx] + maxRight;
        return max(dfs(nums, l, midIdx-1),max(dfs(nums,midIdx+1,r), maxMid));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
