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

        for(auto& p : candidates){
            candidates[p.first] = 0;
            candidates[p.second] = 0;
        }

        for(int num : nums){
            if(candidates.count(num)) candidates[num]++;
        }

        vector<int> res;
        for(auto& p : candidates){
            if(p.second > target) res.push_back(p.first);
        }

        return res;
    }
};