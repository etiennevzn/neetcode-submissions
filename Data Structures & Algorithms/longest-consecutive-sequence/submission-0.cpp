class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        std::set<int> s(nums.begin(), nums.end());
        int curLen = 1, maxLen = 1;
        int prev = *s.begin();

        for(auto it = ++s.begin(); it != s.end(); ++it){
            if(*it == prev+1){
                curLen++;
            }else{
                curLen = 1;
            }
            prev = *it;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
