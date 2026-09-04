class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if(!(sum % p)) return 0;

        int n = nums.size();
        for(int res = 1; res < n; ++res){
            int curSum = 0;
            for(int i = 0; i < n; ++i){
                curSum += nums[i];
                if(i >= res) curSum -= nums[i - res];

                if((sum - curSum) % p == 0) return res;
            }
        }

        return -1;
    }
};