class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,int>> charStack;

        for(const char& c : s){
            if(!charStack.empty() && charStack.back().first == c){
                charStack.back().second++;
            }else{
                charStack.emplace_back(c, 1);
            }

            if(charStack.back().second == k) charStack.pop_back();
        }

        string res;
        for(const auto& p : charStack){
            for(int i = 0; i < p.second; ++i) res.push_back(p.first);
        }

        return res;
    }
};