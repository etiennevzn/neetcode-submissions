class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> dic;
        for(int i = 0; i < order.size(); ++i){
            dic[order[i]] = i;
        }

        for(int pass = 0; pass < s.size(); ++pass){
            for(int i = 0; i < s.size() - 1; ++i){
                if(dic.count(s[i])){
                    if(dic.count(s[i + 1]) && dic[s[i+1]] < dic[s[i]]) swap(s[i], s[i+1]);
                }else{
                    if(dic.count(s[i + 1])) swap(s[i], s[i + 1]);
                }
            }
        }

        return s;
    }
};