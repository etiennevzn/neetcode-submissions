class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() == 1) return s == t;
        if(s.size() != t.size()) return false;
        std::unordered_map<char,int> countS;
        std::unordered_map<char,int> countT;

        for(const auto& c : s){
            countS[c]++;
        }

        for(const auto& c : t){
            countT[c]++;
        }

        for(const auto& p : countS){
            if(countT.find(p.first) == countT.end() || countT[p.first] != p.second) return false;
        }

        return true;
    }
};
