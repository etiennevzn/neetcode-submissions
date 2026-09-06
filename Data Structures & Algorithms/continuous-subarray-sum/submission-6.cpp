class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remains;
        int sum = 0;
        remains[0] = -1;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(remains.count(sum % k)){
                if(i - remains[sum % k] >= 2) return true;
            }else{
                remains[sum % k] = i;
            } 
        }
        return false;
    }
};