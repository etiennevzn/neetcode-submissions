class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];
        int res = INT_MAX;

        while(l <= r){
            int m = l + (r - l) / 2;
            int pairs = 0, i = 0;
            while(i < n - 1){
                if(nums[i + 1] - nums[i] <= m){
                    pairs++;
                    if(pairs == p){
                        res = m;
                        r = m - 1;
                        break;
                    }
                    i++;
                }
                i++;
            } 

            if(i >= n - 1) l = m + 1;
        }

        return res;
    }
};