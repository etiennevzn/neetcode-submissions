class PrefixTree {
private:
    set<string> dict;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        dict.insert(word);
    }
    
    bool search(string word) {
        return dict.count(word);
    }
    
    bool startsWith(string prefix) {
        for(const string& word : dict){
            if(word.size() < prefix.size()) continue;
            if(word.substr(0, prefix.size()) == prefix) return true;
        }

        return false;
    }
};
