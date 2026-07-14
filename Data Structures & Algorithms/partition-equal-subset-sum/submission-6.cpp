class Solution {
    vector<int> memo;

    bool dfs(int i, int cur, int target, vector<int>& nums){
        if(cur == target) return true;
        if(i == nums.size() || cur > target) return false;
        if(memo[cur] != -1) return memo[cur] == 1 ? true : false;

        if(dfs(i+1, cur + nums[i], target, nums)){
            memo[cur + nums[i]] = 1;
            return true;
        }else if(dfs(i+1, cur, target, nums)){
            memo[cur] = 1;
            return true;
        }

        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        memo.resize(sum, -1);
        return dfs(0, 0, sum / 2, nums);
    }
};
