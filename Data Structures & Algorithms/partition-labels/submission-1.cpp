class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = 0, r = 0;
        vector<int> res;
        while(r < s.size()){
            int farthest = 0;
            for(int i = l; i <= r; ++i){
                auto it = find(s.rbegin(), s.rend(), s[i]);
                int idx = s.size() - 1 - distance(s.rbegin(), it);
                farthest = max(farthest, idx);
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
