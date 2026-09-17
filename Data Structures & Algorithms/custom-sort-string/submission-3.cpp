class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for(const char& c : s) count[c - 'a']++;

        string res;
        for(const char& c : order){
            while(count[c - 'a']-- > 0) res.push_back(c);
        }

        for(int i = 0; i < 26; ++i){
            while(count[i]-- > 0) res.push_back('a' + i);
        }

        return res;
    }
};