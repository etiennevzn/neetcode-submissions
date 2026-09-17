class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for(const char& c : s) count[c - 'a']++;

        string res;
        for(const char& c : order){
            while(count[c - 'a']-- > 0) res.push_back(c);
        }

        for(const char& c : s){
            while(count[c - 'a']-- > 0) res.push_back(c);
        }

        return res;
    }
};