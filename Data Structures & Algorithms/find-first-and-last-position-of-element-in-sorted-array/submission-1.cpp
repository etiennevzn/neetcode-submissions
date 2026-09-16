class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};

        int l = 0, r = nums.size(); 
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < target){
                l = m + 1;
            }else{
                r = m;
            }
        }
        int lower_bound = l;

        l = 0, r = nums.size(); 
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] <= target){
                l = m + 1;
            }else{
                r = m;
            }
        }

        if(lower_bound == nums.size() || lower_bound == r) return {-1, -1};
        
        return {lower_bound, r - 1};
    }
};