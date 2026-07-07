class Solution {
private:
    int quickSelect(vector<int>& nums, int k, int l, int r){
        int target = nums.size() - k;
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
            return quickSelect(nums, k, l, p-1);
        }else{
            return quickSelect(nums, k, p+1, r);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k,0,nums.size()-1);
    }
};
