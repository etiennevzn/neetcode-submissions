class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        int remain = total % p;
        if(!remain) return 0;

        int res = nums.size();
        long long curSum = 0;
        unordered_map<int,int> prefixMap;
        prefixMap[0] = -1;

        for(int i = 0; i < nums.size(); ++i){
            curSum = (curSum + nums[i]) % p;
            int prefix = (curSum - remain + p) % p;
            if(prefixMap.count(prefix)) res = min(res, i - prefixMap[prefix]);
            prefixMap[curSum] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};