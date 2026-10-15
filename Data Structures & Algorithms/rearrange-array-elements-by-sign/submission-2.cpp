class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int i = 0, j = 0, n = nums.size();

        while(i < n && j < n){
            while(nums[i] < 0) i++;
            while(nums[j] > 0) j++;
            
            if(i < n) res.push_back(nums[i++]);
            if(j < n) res.push_back(nums[j++]);
        }

        return res;
    }
};