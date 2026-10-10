class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> occurences(26, {-1,-1});
        unordered_set<char> diffs(s.begin(), s.end());
        for(const char& c : diffs){
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == c){
                    if(occurences[c - 'a'].first == -1) occurences[c - 'a'].first = i;
                    occurences[c - 'a'].second = i;
                }
            }
        }

        int res = 0;
        for(const char& c : diffs){
            unordered_set<char> seen;
            for(int i = occurences[c - 'a'].first + 1; i < occurences[c - 'a'].second; ++i){
                seen.insert(s[i]);
            }
            res += seen.size();
        }

        return res;
    }
};