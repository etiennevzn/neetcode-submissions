class Solution {
private:
    void mergeSort(int l, int r, vector<int>& nums){
        if(l >= r) return;

        int m = l + (r - l) / 2;
        mergeSort(l, m, nums);
        mergeSort(m + 1, r, nums);
        merge(l, m, r, nums);
    }

    void merge(int l, int m, int r, vector<int>& nums){
        vector<int> tmp;
        int i = l, j = m + 1;

        while(i <= m && j <= r){
            if(nums[i] <= nums[j]){
                tmp.push_back(nums[i++]);
            }else{
                tmp.push_back(nums[j++]);
            }
        }

        while(i <= m) tmp.push_back(nums[i++]);
        while(j <= r) tmp.push_back(nums[j++]);
        for(int i = l; i <= r; ++i){
            nums[i] = tmp[i - l];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};