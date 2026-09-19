class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefixRemain(k);
        prefixRemain[0] = 1;

        int curSum = 0, res = 0;
        for(int num : nums){
            curSum += num;
            int remain = curSum % k;
            if(remain < 0) remain += k;

            res += prefixRemain[remain];
            prefixRemain[remain]++;
        }

        return res;
    }
};