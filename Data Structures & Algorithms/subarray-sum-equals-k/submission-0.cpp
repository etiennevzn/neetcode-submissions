class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int sum = nums[i];
            if(sum == k) res++;
            for(int j = i+1; j < nums.size(); ++j){
                sum += nums[j];
                if(sum == k) res++;
            }
        }
        return res;
    }
};