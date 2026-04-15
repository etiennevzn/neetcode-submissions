class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        std::unordered_map<int,int> m;

        for(const auto& num : nums){
            m[num]++;
        }

        vector<pair<int,int>> frequencies;
        for(const auto& p : m){
            frequencies.push_back({p.second, p.first});
        }

        std::sort(frequencies.rbegin(), frequencies.rend());
        for(int i = 0; i<k; i++){
            result.push_back(frequencies[i].second);
        }
        return result;
    }
};
