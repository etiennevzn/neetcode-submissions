class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int j = i - 1;
            int tmp = nums[i];
            while(j >= 0 && nums[j] > tmp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
        }
        return nums;
    }
};