class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> occurences(26, {-1,-1});
        unordered_set<char> diffs(s.begin(), s.end());
        for(int i = 0; i < s.size(); ++i){
            const char& c = s[i];
            if(occurences[c - 'a'].first == -1) occurences[c - 'a'].first = i;
            occurences[c - 'a'].second = i;
        }

        int res = 0;
        for(const char& c : diffs){
            int bitmask = 0;
            for(int i = occurences[c - 'a'].first + 1; i < occurences[c - 'a'].second; ++i){
                int n = s[i] - 'a';
                if(bitmask & (1 << n)) continue;
                bitmask |= (1 << n);
                res++;
            }
        }

        return res;
    }
};