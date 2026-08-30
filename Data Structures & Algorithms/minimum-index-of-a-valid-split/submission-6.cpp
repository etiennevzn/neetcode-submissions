class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0, votes = 0;
        for(int num : nums){
            if(votes == 0){
                candidate = num;
            }

            if(num == candidate){
                votes++;
            }else{
                votes--;
            }
        }

        int dCount = 0;
        for(int num : nums){
            if(num == candidate) dCount++;
        }

        int prefixCount = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == candidate) prefixCount++;
            if(prefixCount * 2 > i + 1 && (dCount - prefixCount) * 2 > n - i - 1) return i;
        }

        return -1;
    }
};