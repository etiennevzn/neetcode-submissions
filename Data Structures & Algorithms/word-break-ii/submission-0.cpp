class Solution {
private:
    vector<string> res;
    void dfs(int i, string curWord, string cur, string s, set<string>& wordDict){
        if(i == s.size()){
            if(wordDict.count(curWord)){
                cur += curWord;
                res.push_back(cur);
            }        
            return;
        }

        string before = cur;
        if(wordDict.count(curWord)){
            cur += curWord;
            cur += " ";
            dfs(i, "", cur, s, wordDict);
        }

        dfs(i + 1, curWord + s[i], before, s, wordDict);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        dfs(0, "", "", s, dict);
        return res;
    }
};