class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cntK = 0;
        for(int num : nums) if(num == k) cntK++;

        int maxF = cntK;
        for(int candidate = 1; candidate <= 50; ++candidate){
            if(candidate == k) continue;

            int cur = 0;
            for(int i = 0; i < nums.size(); ++i){
                cur += (nums[i] == candidate) ? 1 : (nums[i] == k) ? -1 : 0;
                cur = max(0, cur);
                maxF = max(maxF, cntK + cur);
            }
        }

        return maxF;
    }
};