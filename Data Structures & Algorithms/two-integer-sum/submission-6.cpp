class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(idx.count(target - num)){
                return {idx[target - num], i};
            }
            idx[num] = i; 
        }

        return {-1};
    }
};
