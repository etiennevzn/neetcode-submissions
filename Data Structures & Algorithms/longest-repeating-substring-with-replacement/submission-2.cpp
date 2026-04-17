class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res = 0;
        int l = 0;
        int maxVal = 0;

        for(int r = 0; r<s.size(); r++){
            count[s[r]]++;
            maxVal = max(maxVal, count[s[r]]);

            while((r-l+1) - maxVal > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }

        return res;
    }
};
