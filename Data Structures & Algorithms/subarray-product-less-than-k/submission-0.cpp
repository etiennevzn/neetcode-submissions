class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        size_t l = 0;
        int windowProduct = 1, res = 0;

        for(size_t r = 0; r < nums.size(); ++r){
            windowProduct *= nums[r];
            while(windowProduct >= k){
                windowProduct /= nums[l++];
            }
            res += r - l + 1;
        }

        return res;
    }
};