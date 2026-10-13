class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int res = 0;
        size_t l = 0;

        for(size_t r = 0; r < nums.size(); ++r){
            ms.insert(nums[r]);
            while(*ms.rbegin() - *ms.begin() > limit){
                ms.erase(ms.find(nums[l]));
                l++;
            }
            res = max(res, (int)(r - l + 1));
        }

        return res;
    }
};