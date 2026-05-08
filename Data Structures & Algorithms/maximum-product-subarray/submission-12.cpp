class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0];
        int res = curMax;
        for(size_t i = 1; i < nums.size(); ++i){
            int temp = curMax;
            curMax = max(nums[i], max(curMax*nums[i], curMin*nums[i]));
            curMin = min(nums[i], min(temp*nums[i], curMin*nums[i]));
            res = max(res, curMax);

            if(nums[i] == 0){
              curMax = curMin = 1;  
            }
        }

        return res;
    }
};
