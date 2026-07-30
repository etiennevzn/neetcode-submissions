class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        int i = 1;
        while(true){
            if(!count.count(i++) && i - 1 > 0) return i - 1;
        }

        return -1;
    }
};