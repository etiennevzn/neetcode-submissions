class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        for(int num : nums) count[num]++;

        int dominant;
        for(const auto& [num, c] : count){
            if(c * 2 > n){
                dominant = num;
                break;
            }
        }

        int prefixCount = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == dominant) prefixCount++;
            if(prefixCount * 2 > i + 1 && (count[dominant] - prefixCount) * 2 > n - i - 1) return i;
        }

        return -1;
    }
};