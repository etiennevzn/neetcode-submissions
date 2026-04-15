class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> numMap;
        for(const auto& num : nums){
            numMap[num]++;
            if(numMap[num] > 1) return true;
        }
        return false;
    }
};