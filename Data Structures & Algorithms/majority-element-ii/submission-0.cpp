class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        unordered_map<int, int> count;
        unordered_set<int> res;

        for(int num : nums){
            if(++count[num] > target) res.insert(num);
        }

        return vector<int>(res.begin(), res.end());
    }
};