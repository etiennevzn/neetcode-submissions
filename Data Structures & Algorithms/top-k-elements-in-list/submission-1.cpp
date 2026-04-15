class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> result;

        for(const int& num : nums) count[num]++;

        for(const auto& pair : count){
            freq[pair.second].push_back(pair.first);
        }

        for(int i = freq.size() - 1; i>0; --i){
            for(const int& num : freq[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            } 
        }

        return result;
    }
};
