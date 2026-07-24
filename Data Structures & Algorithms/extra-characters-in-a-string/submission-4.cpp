class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode(){
        for(int i = 0; i < 26; ++i) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void addWord(const string& word){
        TrieNode* cur = root;
        for(const char& c : word){
            if(!cur->children[c - 'a']) cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for(const string& word : dictionary){
            trie.addWord(word);
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; --i){
            dp[i] = 1 + dp[i + 1];
            TrieNode* cur = trie.root;
            for(int j = i; j < n; j++){
                if(!cur->children[s[j] - 'a']) break;
                cur = cur->children[s[j] - 'a'];
                if(cur->isWord){
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};