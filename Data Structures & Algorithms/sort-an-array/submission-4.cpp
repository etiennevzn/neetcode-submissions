class Solution {
private:
    void mergeSort(int l, int r, vector<int>& nums){
        if(l >= r) return;

        int m = (l + r) / 2;
        mergeSort(l, m, nums);
        mergeSort(m + 1, r, nums);
        merge(l, m, r, nums);
    }

    void merge(int l, int m, int r, vector<int>& nums){
        int i = l, j = m + 1;
        vector<int> temp;
        while(i <= m && j <= r){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);

        for(int i = l; i <= r; ++i){
            nums[i] = temp[i - l];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};