class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1;
        int res = nums[0];
        for(int num : nums){
            int temp = curMax*num;
            curMax = max(num, max(curMax*num, curMin*num));
            curMin = min(num, min(temp, curMin*num));
            res = max(res, curMax);
        }

        return res;
    }
};
