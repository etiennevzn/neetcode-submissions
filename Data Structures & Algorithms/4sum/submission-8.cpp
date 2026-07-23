class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            for(int j = i + 1; j < nums.size(); ++j){
                if(j > i + 1 && nums[j - 1] == nums[j]) continue;
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    long long curSum = (long long)nums[i] + nums[j] + nums[r] + nums[l];
                    if(curSum == target){
                        res.push_back({nums[i], nums[j], nums[r--], nums[l++]});
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }else if(curSum < target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }

        return res;
    }
};