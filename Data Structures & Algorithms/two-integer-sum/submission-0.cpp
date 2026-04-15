class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            int difference = target-nums[i];
            if(hashmap.count(difference)){
                vector<int> final = {i, hashmap[difference]};
                std::sort(final.begin(),final.end());
                return final;
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
