class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zCount = 0;

        for(const int& num : nums){
            if(num !=0) prod*=num;
            else zCount++;
        }

        if(zCount > 1) return vector<int>(nums.size(), 0);

        vector<int> res(nums.size());
        for(int i = 0; i<nums.size(); i++){
            if(zCount == 1){
                if(nums[i] == 0){
                    res[i] = prod;
                }else{
                    res[i] = 0;
                }
            }else{
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};