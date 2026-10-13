class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIdx = 1, cnt = 1;
        for(size_t i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1]){
                cnt++;
            }else{
                cnt = 1;
            }

            if(cnt < 3){
                nums[insertIdx] = nums[i];
                insertIdx++;
            }
        }

        return insertIdx;
    }
};