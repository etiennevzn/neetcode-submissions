class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> countS1(26);
        vector<int> countS2(26);
        
        for(const char& c : s1){
            countS1[c - 'a']++;
        }

        int l = 0;
        int r = l;
        while(r < s1.size()){
            countS2[s2[r] - 'a']++;
            r++;
        }

        if(countS1 == countS2) return true;
        while(r < s2.size()){
            countS2[s2[r] - 'a']++;
            countS2[s2[l] - 'a']--;
            r++;
            l++;
            if(countS1 == countS2) return true;
        }
        return false;
    }
};
