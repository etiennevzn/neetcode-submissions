class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numSet(nums.begin(), nums.end());
       int maxLen = 0;
       for(const int& num : nums){
            if(!numSet.count(num-1)){
                int curLen = 1;
                while(numSet.count(num+curLen)){
                    curLen++;
                }
                maxLen = std::max(maxLen, curLen);
            }
       } 
       return maxLen;
    }
};
