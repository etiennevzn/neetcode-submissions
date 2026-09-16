class Solution {
private:
    int binarySearch(int target, const vector<int>& nums, int n){
        int l = 0, r = n; 

        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < target){
                l = m + 1;
            }else{
                r = m;
            }
        }

        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lower_bound = binarySearch(target, nums, n);
        if(lower_bound == nums.size() || nums[lower_bound] != target) return {-1, -1};
        
        return {lower_bound, binarySearch(target + 1, nums, n) - 1};
    }
};