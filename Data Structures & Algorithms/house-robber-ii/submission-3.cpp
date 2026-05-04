class Solution {
private:
    int findMax(vector<int>& nums){
        int rob1 = 0, rob2 = 0;
        for(int num : nums){
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> houses1(nums.begin(), nums.end()-1);
        vector<int> houses2(nums.begin()+1, nums.end());

        int res = max(findMax(houses1), findMax(houses2));
        return res;
    }
};
