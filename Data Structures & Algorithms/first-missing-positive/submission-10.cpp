class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 

        while(i < n){
            if(nums[i] <= 0 || nums[i] > n){
                i++;
                continue;
            }

            int index = nums[i] - 1;
            if(nums[index] == nums[i]){
                i++;
            }else{
                swap(nums[index], nums[i]);
            }
        }

        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};