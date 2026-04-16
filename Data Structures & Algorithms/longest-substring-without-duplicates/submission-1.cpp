class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> charSet;
        int l = 0;

        for(int r = 0; r<s.size(); ++r){
            while(charSet.count(s[r])){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r-l+1);
        }

        return res;
    }
};
