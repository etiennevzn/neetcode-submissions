class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[l];

        while(l <= r){
            if(nums[l] < nums[r]) return min(res, nums[l]);
            
            int mid = (l+r)/2;
            if(nums[l] <= nums[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
            res = min(res, nums[mid]);
        }

        return res;
    }
};
