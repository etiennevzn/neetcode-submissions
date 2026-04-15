class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int curPrefix = 1;
        res[0] = 1;
        for(int i = 1; i<nums.size(); i++){
            res[i] = curPrefix * nums[i-1];
            curPrefix = res[i];
        }

        int curPostfix = 1;
        for(int i = nums.size()-2; i>=0; i--){
            res[i] *= (curPostfix * nums[i+1]);
            curPostfix *= nums[i+1];
        }
        return res;
    }
};