class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = 0, r = 0;
        vector<int> res;
        unordered_map<char, int> lastIndex;
        for(int i = 0; i < s.size(); ++i){
            lastIndex[s[i]] = i;
        }

        while(r < s.size()){
            int farthest = 0;
            for(int i = l; i <= r; ++i){
                farthest = max(farthest, lastIndex[s[i]]);
            }
            if(farthest > r){
                r = farthest;
                continue;
            }
            res.push_back(r - l + 1);
            l = r + 1; 
            r = l;
        }

        return res;
    }
};
