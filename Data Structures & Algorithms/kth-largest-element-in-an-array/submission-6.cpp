class Solution {
private:
    int quickSelect(vector<int>& nums, int target, int l, int r){
        int p = l;

        for(int i = l; i < r; ++i){
            if(nums[i] < nums[r]){
                swap(nums[i], nums[p++]);
            }
        }
        swap(nums[r], nums[p]);

        if(p == target){
            return nums[p];
        }else if(p > target){
            return quickSelect(nums, target, l, p-1);
        }else{
            return quickSelect(nums, target, p+1, r);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return quickSelect(nums,target,0,nums.size()-1);
    }
};
