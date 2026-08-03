class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        long r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while(l <= r){
            int m = l + (r - l)/2;
            int sum = 0, groups = 0;

            bool canSplit = true;
            for(int num : nums){
                sum += num;
                if(sum > m){
                    groups++;
                    sum = num;
                    if(groups >= k){
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