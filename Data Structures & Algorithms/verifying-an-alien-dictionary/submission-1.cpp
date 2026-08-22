class Solution {
private:
    bool areSorted(const string& a, const string& b, const string& order){
        int i = 0, j = 0;
        int lenA = a.size(), lenB = b.size();

        bool sorted = true;
        bool equal = true;
        while(i < lenA && j < lenB){
            if(a[i] != b[j]) equal = false;
            if(!equal){
                for(const char& c : order){
                    if(a[i] == c) return true;
                    if(b[j] == c) return false;
                }
            }
            i++;
            j++;
        }

        return a.size() <= b.size() ? true : false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n == 1) return true;
        int pair1 = 0, pair2 = 1;

        while(pair2 < n){
            if(!areSorted(words[pair1], words[pair2], order)) return false;
            pair1++;
            pair2++;
        }

        return true;
    }
};