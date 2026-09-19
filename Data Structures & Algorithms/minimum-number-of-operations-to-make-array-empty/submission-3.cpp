class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        int res = 0;
        for(auto& [_, n] : count){
            if(n == 1) return -1;
            res += n / 3;
            res += (n % 3 != 0) ? 1 : 0;
        }

        return res;
    }
};