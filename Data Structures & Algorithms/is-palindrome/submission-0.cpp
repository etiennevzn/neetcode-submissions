class Solution {
public:
    bool isPalindrome(string s) {
        string newStr;
        for(const char& c : s){
            if(isalnum(c)) newStr += tolower(c);
        }
        string rnewStr = newStr;
        reverse(rnewStr.begin(), rnewStr.end());
        return  rnewStr == newStr;
    }
};
