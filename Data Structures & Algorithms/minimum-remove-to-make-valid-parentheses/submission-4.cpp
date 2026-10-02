class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> remove(n, false);

        int opened = 0;
        for(int i = 0; i < n; ++i){
            const char& c = s[i];
            if(c == '(') opened++;
            if(c == ')'){
                opened--;
                if(opened < 0){
                    remove[i] = true;
                    opened = 0;
                }
            }
        }

        int closed = 0;
        for(int i = n - 1; i >= 0; --i){
            const char& c = s[i];
            if(c == ')') closed++;
            if(c == '('){
                closed--;
                if(closed < 0){
                    remove[i] = true;
                    closed = 0;
                }
            }
        }

        string res;
        for(int i = 0; i < n; ++i){
            if(!remove[i]){
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
