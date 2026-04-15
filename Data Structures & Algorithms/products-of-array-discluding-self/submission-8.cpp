class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int curPrefix = 1;
        for(int i = 0; i<nums.size(); i++){
            res[i] = curPrefix;
            curPrefix *= nums[i];
        }

        int curPostfix = 1;
        for(int i = nums.size()-1; i>=0; i--){
            res[i] *= curPostfix;
            curPostfix *= nums[i];
        }
        return res;
    }
};