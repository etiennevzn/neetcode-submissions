class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> maxMoney(nums.size(), 0);
        maxMoney[0] = nums[0];
        maxMoney[1] = max(nums[1], nums[0]);

        for(size_t i = 2; i < nums.size(); ++i){
            maxMoney[i] = max(nums[i] + maxMoney[i-2], maxMoney[i-1]);
        }

        return maxMoney[nums.size() - 1];
    }
};