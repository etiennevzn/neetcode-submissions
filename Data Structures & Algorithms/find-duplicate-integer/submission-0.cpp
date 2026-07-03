class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> numMap;
        for(const int& num : nums){
            if(numMap.count(num)) return num;
            numMap[num] = 1;
        }
        return -1;
    }
};
