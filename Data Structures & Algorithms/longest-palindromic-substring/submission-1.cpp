class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        int resLen = 1;

        for(int i = 0; i < s.size(); ++i){
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }

            if(r-l-1 > resLen){
                resLen = r-l-1;
                res = l+1;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }

            if(r-l-1 > resLen){
                resLen = r-l-1;
                res = l+1;
            }
        }

        return s.substr(res, resLen);
    }
};
