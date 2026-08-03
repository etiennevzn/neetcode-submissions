class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = l + (r - l)/2;
            if(nums[m] == target) return true;

            if(nums[l] == nums[m] && nums[m] == nums[r]){
                if(r - 1 >= 0 && nums[r] == nums[r - 1]){
                    r--;
                }else{
                    if(l + 1 < nums.size() && nums[l] == nums[l + 1]) l++;
                }
            }

            m = l + (r - l)/2;
            if(nums[m] == target) return true;

            if(nums[m] >= nums[l]){
                if(target < nums[l] || target > nums[m]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else{
                if(target > nums[r] || target < nums[m]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
        }

        return false;
    }
};