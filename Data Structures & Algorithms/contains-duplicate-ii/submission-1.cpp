class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); ++i){
            if(count.count(nums[i]) && abs(count[nums[i]] - i) <= k) return true;
            count[nums[i]] = i;
        }
        return false;
    }
};