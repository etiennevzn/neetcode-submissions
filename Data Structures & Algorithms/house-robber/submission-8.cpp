class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next1 = 0, next2 = 0;
        for(int i = n - 1; i >= 0; --i){
            int rob = nums[i] + next2;
            int skip = next1;
            int cur = max(rob, skip);
            next2 = next1;
            next1 = cur;
        }

        return next1;
    }
};
