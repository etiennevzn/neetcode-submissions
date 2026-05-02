class Solution {
private:
    bool dfs(char c){
        if(state[c] == 1) return true;
        if(state[c] == 2) return false;

        state[c] = 1;
        for(const char& ch : adj[c]){
            if(dfs(ch)){
                return true;
            }
        }
        state[c] = 2;
        res.push_back(c);
        return false;
    }
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> state;
    string res;

    string foreignDictionary(vector<string>& words) {
        for(const string& word : words){
            for(const char& c : word){
                adj[c];
                state[c] = 0;
            }
        }

        for(size_t i = 0; i < words.size()-1; ++i){
            const string& w1 = words[i], & w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());

            if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)){
                return "";
            }

            for(size_t j = 0; j < minLen; ++j){
                if(w1[j] != w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for(const auto& pair : adj){
            if(dfs(pair.first)){
                return "";
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
