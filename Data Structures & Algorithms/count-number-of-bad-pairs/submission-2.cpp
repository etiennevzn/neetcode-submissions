class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        unordered_map<int,long long> differencesCount;

        for(int i = 0; i < n; ++i){
            differencesCount[nums[i] - i]++;
        }

        long long goodPairs = 0;
        for(const auto& p : differencesCount){
            long long nIdx = p.second;
            goodPairs += nIdx * (nIdx - 1) / 2;
        }

        return totalPairs - goodPairs;
    }
};
