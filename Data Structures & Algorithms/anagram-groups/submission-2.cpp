class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        std::unordered_map<string, vector<string>> stringMap;
        for(const auto& s : strs){
            string sortedS = s;
            std::sort(sortedS.begin(), sortedS.end());
            stringMap[sortedS].push_back(s);
        }

        for(const auto& p : stringMap){
            ans.push_back(p.second);
        }

        return ans;
    }
};
