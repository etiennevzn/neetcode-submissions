class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> memo(3, false);

        for(const auto& triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) continue;

            for(int i = 0; i < triplet.size(); ++i){
                if(triplet[i] == target[i]) memo[i] = true;
            }
        }

        return memo[0] && memo[1] && memo[2];
    }
};
