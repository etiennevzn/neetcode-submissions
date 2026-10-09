class Solution {
private:
    void quickSort(int begin, int end, vector<int>& nums){
        if(begin >= end) return;

        int pivot = end, insertPos = begin;

        for(int i = insertPos; i < pivot; ++i){
            if(nums[i] <= nums[pivot]){
                swap(nums[i], nums[insertPos]);
                insertPos++;
            }
        }

        swap(nums[pivot], nums[insertPos]);
        insertPos++;

        quickSort(begin, insertPos - 2, nums);
        quickSort(insertPos, end, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }
};