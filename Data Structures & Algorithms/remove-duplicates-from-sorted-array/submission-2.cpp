class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            nums[idx++] = nums[i];
        }

        return idx;
    }
};