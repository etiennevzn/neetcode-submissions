class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, l = 0, r = 0, cur = 0;
        while(r < nums.size() || cur >= target){
            if(cur >= target){
                res = min(res, r - l);
                cur -= nums[l++];
            }else{
                cur += nums[r++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};