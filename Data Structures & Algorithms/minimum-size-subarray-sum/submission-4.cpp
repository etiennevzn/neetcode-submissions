class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, l = 0, cur = 0;
        for(int r = 0; r < nums.size(); ++r){
            cur += nums[r];
            while(cur >= target){
                res = min(res, r - l + 1);
                cur -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};