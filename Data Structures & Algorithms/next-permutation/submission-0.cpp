class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = n - 2;

        while(pivot >= 0 && nums[pivot] >= nums[pivot + 1]) pivot--;
        if(pivot >= 0){
            int s = n - 1;
            while(nums[s] <= nums[pivot]) s--;
            swap(nums[pivot], nums[s]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());    
    }
};