class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> count;
        for(const auto& num : nums){
            count[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for(const auto&p : count){
            freq[p.second].push_back(p.first);
        }

        vector<int> result;
        for(int i = freq.size()-1; i>=0; i--){
            for(const auto& num : freq[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            } 
        }
        return result;
    }
};
