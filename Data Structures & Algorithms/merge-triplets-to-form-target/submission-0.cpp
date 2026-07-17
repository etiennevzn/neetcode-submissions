class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> memo(3, false);

        for(const auto& triplet : triplets){
            bool usable = true;
            for(int i = 0; i < triplet.size(); ++i){
                if(triplet[i] > target[i]) usable = false;
            }
            if(!usable) continue;

            for(int i = 0; i < triplet.size(); ++i){
                if(!memo[i] && triplet[i] == target[i]) memo[i] = true;
            }
        }

        return memo[0] && memo[1] && memo[2];
    }
};
