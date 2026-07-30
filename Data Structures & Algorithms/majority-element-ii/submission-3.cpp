class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> candidates;
        int target = nums.size() / 3;

        for(int num : nums){
            candidates[num]++;
            if(candidates.size() > 2){
                unordered_map<int,int> newCandidates;
                for(const auto& p : candidates){
                    if(p.second > 1){
                        newCandidates[p.first] = p.second - 1;
                    }
                }
                candidates = newCandidates;
            }
        }

        vector<int> res;
        for(auto& p : candidates){
            int freq = 0;
            for(int num : nums){
                if(num == p.first) freq++;
            }
            if(freq > target) res.push_back(p.first);
        }

        return res;
    }
};