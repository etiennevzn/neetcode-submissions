class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(s[0] == '-'){
            std::reverse(s.begin() + 1, s.end());
        }else{
            std::reverse(s.begin(), s.end());
        }
        long long res = stoll(s);
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
