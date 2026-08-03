class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        long r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while(l <= r){
            int m = l + (r - l)/2;
            int sum = 0;
            int groups = k;

            bool canSplit = true;
            for(int i = 0; i < nums.size(); ++i){
                sum += nums[i];
                if(sum > m){
                    groups--;
                    sum = nums[i];
                    if(groups <= 0){
                        l = m + 1;
                        canSplit = false;
                        break;
                    }
                }
            }

            if(canSplit){
                res = m;
                r = m - 1;
            }
        }

        return res;
    }
};