class Solution {
private:
    unordered_map<string, bool> memo;
    bool isConcat(const string& word, const unordered_set<string>& wordSet){
        if(memo.count(word)) return memo[word];

        bool res = false;

        for(int i = 0; i < word.size(); ++i){
            string prefix = word.substr(0, i);
            string suffix = word.substr(i, word.size() - i);
            if((wordSet.count(prefix) && wordSet.count(suffix)) || (wordSet.count(prefix) && isConcat(suffix, wordSet))){
                res = true;
                break;
            }
        }

        return memo[word] = res;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet = unordered_set<string>(words.begin(), words.end());

        vector<string> res;
        for(const string& word : words){
            if(isConcat(word, wordSet)) res.push_back(word);
        }

        return res;
    }
};