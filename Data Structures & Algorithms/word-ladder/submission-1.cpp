class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        unordered_map<string, vector<string>> patterns;
        wordList.push_back(beginWord);

        for(const auto& word : wordList){
            for(int j = 0; j < word.size(); ++j){
                string pattern = word.substr(0, j) + "*" + word.substr(j+1);
                patterns[pattern].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);
        int res = 1;
        unordered_set<string> visited = {beginWord};

        while(!q.empty()){
            int qLen = q.size();
            for(int i = 0; i < qLen; ++i){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return res;

                for(int j = 0; j < cur.size(); ++j){
                    string pattern = cur.substr(0, j) + "*" + cur.substr(j+1);
                    for(const auto& word : patterns[pattern]){
                        if(!visited.count(word)){
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
