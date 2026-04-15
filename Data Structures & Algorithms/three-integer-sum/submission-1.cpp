class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size()-1;

            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == -nums[i]){
                    res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                } 
                else if(sum < -nums[i]) l++;
                else if(sum > -nums[i]) r--;
            }
        }

        return res;
    }
};
