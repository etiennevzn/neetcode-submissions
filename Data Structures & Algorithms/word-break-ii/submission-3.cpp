struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie{
public:
    TrieNode* root;

    Trie() : root(new TrieNode()){}
    void addWord(const string& word){
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
private:
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(int i, string& s, Trie& t){
        if(i == s.size()) return {""};
        if(memo.count(i)) return memo[i];

        TrieNode* curr = t.root;
        vector<string> res;

        for(int j = i; j < s.size(); ++j){
            if(!curr->children.count(s[j])) break;
            curr = curr->children[s[j]];

            if(curr->isWord){
                for(const string& suffix : dfs(j + 1, s, t)){
                    if(suffix.empty()){
                        res.push_back(s.substr(i, j - i + 1));
                    }else{
                        res.push_back(s.substr(i, j - i + 1) + " " + suffix);
                    }
                }
            }
        }

        return memo[i] = res;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(const string& word : wordDict){
            t.addWord(word);
        }

        return dfs(0, s, t);
    }
};