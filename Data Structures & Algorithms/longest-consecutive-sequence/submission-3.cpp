class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numSet(nums.begin(), nums.end());
       int maxLen = 0;
       for(const int& num : nums){
            int curLen = 0;
            if(numSet.find(num-1) == numSet.end()){
                curLen = 1;
                while(numSet.find(num + curLen) != numSet.end()){
                    curLen++;
                }
                maxLen = std::max(maxLen, curLen);
            }
       } 
       return maxLen;
    }
};
