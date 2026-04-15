class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;
        vector<vector<string>> returned;
        for(const auto& s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            result[sortedS].push_back(s);
        }
        for(const auto& pair : result){
            returned.push_back(pair.second);
        }
        return returned;
    }
};
