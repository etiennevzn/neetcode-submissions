class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        int i = 1;
        while(true){
            if(!count.count(i++)) return i - 1;
        }
    }
};