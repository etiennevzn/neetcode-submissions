class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zCount = 0;
        int product = 1;

        for(const int& num : nums){
            if(num == 0){
                zCount++;
            }else{
                product*=num;
            }
        }

        if(zCount > 1) return vector<int>(nums.size(),0);
        vector<int> res(nums.size(), 0);
        for(int i = 0; i<nums.size(); i++){
          if(zCount == 1){
            res[i] = nums[i] == 0 ? product : 0;
          }else{
            res[i] = product / nums[i];
          }
        }
        return res;
    }
};