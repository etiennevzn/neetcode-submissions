class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<int> tempResult;
        vector<int> result;
        std::unordered_map<int,int> m;
        for(const auto& num : nums){
            m[num]++;
        }
        vector<int> frequencies;
        for(const auto& p : m){
            frequencies.push_back(p.second);
        }
        std::sort(frequencies.rbegin(), frequencies.rend());
        for(int i = 0; i<k; i++){
            for(const auto& p : m){
                if(p.second == frequencies[i]) tempResult.insert(p.first);
            }
        }
        for(const auto& num : tempResult){
            result.push_back(num);
        }
        return result;
    }
};
