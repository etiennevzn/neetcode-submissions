class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixCount(n);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int count = 0;
        for(int i = 0; i < n; ++i){
            int l = words[i].size() - 1;
            if(vowels.count(words[i][0]) && vowels.count(words[i][l])) count++;
            prefixCount[i] = count;
        }

        vector<int> res;
        for(const vector<int>& query : queries){
            int ri = query[0] == 0 ? 0 : prefixCount[query[0] - 1];
            res.push_back(prefixCount[query[1]] - ri);
        }

        return res;
    }
};