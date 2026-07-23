class Solution {
private:
    void heapify(int n, int i, vector<int>& nums){
        int l = (i << 1) + 1;
        int r = (i << 1) + 2;

        int largestIdx = i;
        if(l < n && nums[l] > nums[largestIdx]) largestIdx = l;
        if(r < n && nums[r] > nums[largestIdx]) largestIdx = r;

        if(largestIdx != i){
            swap(nums[largestIdx], nums[i]);
            heapify(n, largestIdx, nums);
        }
    }

    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; --i){
            heapify(n, i, nums);
        }

        for(int i = n - 1; i >= 0; --i){
            swap(nums[0], nums[i]);
            heapify(i, 0, nums);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};