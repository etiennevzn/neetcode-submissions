class Solution {
private:
    void partition(int l, int r, vector<int>& nums){
        if(l >= r) return;

        int pivot = l;
        for(int j = l; j <= r; ++j){
            if(nums[j] < nums[r]){
                swap(nums[pivot], nums[j]);
                pivot++;
            }
        }
        swap(nums[pivot], nums[r]);
        partition(pivot + 1, r, nums);
        partition(l, pivot - 1, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        partition(l, r, nums);
        return nums;
    }
};