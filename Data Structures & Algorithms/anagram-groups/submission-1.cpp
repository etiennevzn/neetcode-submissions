class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;
        vector<vector<string>> returned;
        for(const auto& s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 0; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }

            result[key].push_back(s);
        }
        for(const auto& pair : result){
            returned.push_back(pair.second);
        }
        return returned;
    }
};
