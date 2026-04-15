class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(!tmap[s[i]] || tmap[s[i]] != smap[s[i]]) return false;
        }
        return true;
    }
};
