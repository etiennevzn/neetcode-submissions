class Solution {
private:
    int dfs(int i, int target, vector<int>& nums){
        if(i == nums.size()) return 0;
        
        int res = 0;
        target -= nums[i];
        if(target == 0) res++;
        res += dfs(i+1,target, nums); 

        return res;       
    }
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            res += dfs(i, k, nums);
        }
        return res;
    }
};