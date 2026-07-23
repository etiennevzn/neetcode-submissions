class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;
        while(i <= r){
            if(!nums[i]){
                swap(nums[i], nums[l++]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[r--]);
                i--;
            }
            i++;
        }
    }
};