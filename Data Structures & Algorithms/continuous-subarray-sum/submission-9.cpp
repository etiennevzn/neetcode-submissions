class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remains;
        int sum = 0;
        remains[0] = -1;

        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            int r = sum % k;
            if(remains.count(r)){
                if(i - remains[r] >= 2) return true;
            }else{
                remains[r] = i;
            } 
        }
        return false;
    }
};