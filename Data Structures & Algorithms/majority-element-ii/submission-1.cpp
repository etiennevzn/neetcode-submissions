class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        vector<int> res;

        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1]){
                r = i;
            }else{
                if(r - l + 1 > target) res.push_back(nums[r]);
                l = r = i;
            }
        }

        if(r - l + 1 > target) res.push_back(nums[r]);
        return res;
    }
};