class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size();

        while(l < r){
            int mid = l + (r-l)/2;
            if(target <= nums[mid]){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return ((l < nums.size()) && nums[l] == target ? l : -1);
    }
};
