class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int g = gcd(n, m);

        for(int i = 0; i < n; ++i){
            if(str1[i] != str1[i % g]) return "";
        }

        for(int i = 0; i < m; ++i){
            if(str2[i] != str1[i % g]) return "";
        }

        return str1.substr(0,g);
    }
};