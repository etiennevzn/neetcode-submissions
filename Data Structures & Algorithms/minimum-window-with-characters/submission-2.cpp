class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> countWindow;
        pair<int,int> res = {-1, -1};
        int resLen = INT_MAX;

        for(const char& c : t){
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();
        int l = 0;

        for(int r = 0; r<s.size(); ++r){
            countWindow[s[r]]++;
            if(countT.count(s[r]) && countWindow[s[r]] == countT[s[r]]) have++;

            while(have == need){
                if(resLen > (r-l+1)){
                    res = {l, r};
                    resLen = r-l+1;
                }
                countWindow[s[l]]--;
                if(countT.count(s[l]) && countWindow[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
