class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;

        int target = sum / 2;
        int n = nums.size();
        
        unordered_set<int> sums = {0};
        for(int i = n - 1; i >= 0; --i){
            unordered_set<int> newSums = sums;
            for(int sum : sums){
                int newSum = sum + nums[i];
                if(newSum == target) return true;
                newSums.insert(newSum);
            }
            sums = newSums;
        }

        return false;
    }
};
