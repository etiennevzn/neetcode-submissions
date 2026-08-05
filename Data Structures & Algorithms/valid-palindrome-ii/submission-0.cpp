class Solution {
    bool isPalindrome(const string& s, int l, int r, bool modified){
        if(l >= r) return true;
        if(s[l] != s[r] && modified) return false;
        if(s[l] != s[r]) return isPalindrome(s, l, r - 1, true) || isPalindrome(s, l + 1, r, true);
        return isPalindrome(s, l + 1, r - 1, modified);
    }
public:
    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.size() - 1, false);
    }
};