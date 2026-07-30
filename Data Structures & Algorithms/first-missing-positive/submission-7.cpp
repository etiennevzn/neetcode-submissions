class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        for(int i = 1; i < count.size() + 1; ++i){
            if(!count.count(i)) return i;
        }
    }
};