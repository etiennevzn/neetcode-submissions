class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        for(int i = 0; i < count.size(); ++i){
            if(!count.count(i+1)) return i+1;
        }
    }
};