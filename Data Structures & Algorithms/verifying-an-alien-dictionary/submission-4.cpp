class Solution {
private:
    vector<int> rank = vector<int>(26);
    bool areSorted(const string& a, const string& b){
        int lenA = a.size(), lenB = b.size();

        for(int i = 0; i < min(lenA, lenB); ++i){
            if(a[i] != b[i]){
                return rank[a[i] - 'a'] < rank[b[i] - 'a'];
            }
        }

        return lenA <= lenB;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; ++i) rank[order[i] - 'a'] = i;

        for(int i = 0; i < words.size() - 1; ++i){
            if(!areSorted(words[i], words[i + 1])) return false;
        }

        return true;
    }
};