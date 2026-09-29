class Solution {
private:
    int possible(int cap, int k, const vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= cap){
                k--;
                i++;
            }
            if(k == 0) return true;
        }

        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int res = INT_MAX;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(possible(m, k, nums)){
                res = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        return res;
    }
};