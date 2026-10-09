class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, res = 0, r = 0;
        long long windowSum = 0;

        for(int r = 0; r < nums.size(); ++r){
            windowSum += nums[r];
            while(1LL * (r - l + 1) * nums[r] > k + windowSum){
                windowSum -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};