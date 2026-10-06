class Solution {
private:
    vector<int> memo;
    bool isConcat(int i, const string& candidate, const vector<string>& words){
        if(i == candidate.size()) return true;
        if(memo[i] != -1) return memo[i];

        int res = false;
        for(const string& word : words){
            if(candidate == word || candidate.size() - i < word.size()) continue;

            if(candidate.substr(i, word.size()) == word){
                res |= isConcat(i + word.size(), candidate, words);
            }
            if(res) break;
        }

        return memo[i] = res;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int smallest = INT_MAX;
        for(const string& word : words){
            smallest = min(smallest, (int)word.size());
        }

        vector<string> candidates;
        for(const string& word : words){
            if(word.size() >= 2 * smallest) candidates.push_back(word);
        }

        vector<string> res;
        for(const string& candidate : candidates){
            memo.assign(candidate.size(), -1);
            if(isConcat(0, candidate, words)) res.push_back(candidate);
        }

        return res;
    }
};