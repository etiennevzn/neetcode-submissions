class Trie{

};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end());
        res.push_back(folder[0]);

        for(int i = 1; i < folder.size(); ++i){
            if(folder[i].find(res.back() + "/") != 0) res.push_back(folder[i]);
        }

        return res;
    }
};