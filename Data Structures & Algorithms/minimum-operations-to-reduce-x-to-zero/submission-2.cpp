class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int numsSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(numsSum == x) return n;

        int target = numsSum - x;
        int windowSum = 0; 
        int res = 0;

        int l = 0;
        for(int r = 0; r < n; ++r){
            windowSum += nums[r];
            while(windowSum > target && l < r){
                windowSum -= nums[l++];
            }
            if(windowSum == target) res = max(res, r - l + 1);
        }

        if(res == 0) return -1;
        return n - res;
    }
};
