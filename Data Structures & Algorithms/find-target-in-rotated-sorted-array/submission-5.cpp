class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] < nums[r]){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        int pivotIndex = l;
        l = 0;
        r = nums.size() - 1;

        if(target >= nums[pivotIndex] && target <= nums[r]){
            l = pivotIndex;
        }else{
            r = pivotIndex-1;
        }

        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return -1;
    }


};
