class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> ansMap;

        for(int i = 0; i<nums.size(); i++){
            if(ansMap.count(target-nums[i])){
                return {ansMap[target-nums[i]], i};
            }
            ansMap.insert({nums[i], i});
        }
        return {};
    }
};