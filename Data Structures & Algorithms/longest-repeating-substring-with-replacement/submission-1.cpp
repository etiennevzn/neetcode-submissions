class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res = 0;
        int l = 0;

        for(int r = 0; r<s.size(); r++){
            count[s[r]]++;

            int maxVal = 0;
            for (auto& [k, v] : count) {
                maxVal = max(maxVal, v);
            }

            int replacements = (r-l+1) - maxVal;
            while(replacements > k){
                count[s[l]]--;
                l++;
                replacements = (r-l+1) - maxVal;
            }
            res = max(res, r-l+1);
        }

        return res;
    }
};
