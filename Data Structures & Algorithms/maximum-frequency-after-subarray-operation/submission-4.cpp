class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cntK = 0;
        for(int num : nums) if(num == k) cntK++;

        int maxF = cntK;
        for(int candidate = 1; candidate <= 50; ++candidate){
            if(candidate == k) continue;
            
            int maxi = 0, cur = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == candidate){
                    cur = max(cur + 1, 1);
                    maxi = max(maxi, cur);
                }else if(nums[i] == k){
                    cur--;
                }
            }
            maxF = max(maxF, cntK + maxi);
        }

        return maxF;
    }
};