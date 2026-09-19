class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSums(n);

        int curSum = 0;
        for(int i = 0; i < n; ++i){
            curSum += nums[i];
            prefixSums[i] = curSum;
        }

        unordered_map<int,vector<int>> count;
        count[0].push_back(-1);
        for(int i = 0; i < n; ++i) count[prefixSums[i] % k].push_back(i);

        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int idx : count[prefixSums[i] % k]){
                if(idx < i) res++;
            }
        }

        return res;
    }
};