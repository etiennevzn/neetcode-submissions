class Solution {
private:  
    vector<int> memo;

    int dfs(int i, const string& s, unordered_set<string>& dictionary){
        if(i == s.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int skip = 1 + dfs(i + 1, s, dictionary);
        int include = INT_MAX;
        for(int j = i; j < s.size(); j++){
            if(dictionary.count(s.substr(i, j - i + 1))){
                include = min(include, dfs(j + 1, s, dictionary));
            }
        }

        memo[i] = min(skip, include);
        return memo[i];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dic = unordered_set<string>(dictionary.begin(), dictionary.end());
        memo.resize(s.size(), -1);
        return dfs(0, s, dic);
    }
};