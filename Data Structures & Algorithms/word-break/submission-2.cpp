class Solution {
private:
    unordered_map<string, bool> mem;
    bool dfs(string s, vector<string>& wordDict, int idx){
        if(idx >= s.size()) return true;
        if(mem.count(s.substr(idx, s.size()-idx))) return mem[s.substr(idx, s.size()-idx)];
        for(const string& word : wordDict){
            if(s.substr(idx, word.size()) == word){
                if(dfs(s, wordDict, idx+word.size())){
                    mem[s.substr(idx, s.size()-idx)] = true;
                    return true;
                }
            }
        }
        mem[s.substr(idx, s.size()-idx)] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }
};
