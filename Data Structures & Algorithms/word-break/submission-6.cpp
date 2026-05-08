class Solution {
private:
    unordered_map<int, bool> mem;
    bool dfs(string s, vector<string>& wordDict, int idx){
        if(idx >= s.size()) return true;
        if(mem.count(idx)) return mem[idx];
        for(const string& word : wordDict){
            if(s.substr(idx, word.size()) == word){
                if(dfs(s, wordDict, idx+word.size())){
                    mem[idx] = true;
                    return true;
                }
            }
        }
        mem[idx] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }
};
