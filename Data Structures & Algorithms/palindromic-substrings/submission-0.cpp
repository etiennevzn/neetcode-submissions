class Solution {
public:
    int countSubstrings(string s) {
        int res = s.size();

        for(int i = 0; i < s.size(); ++i){
            int l = i-1;
            int r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                l--;
                r++;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};
