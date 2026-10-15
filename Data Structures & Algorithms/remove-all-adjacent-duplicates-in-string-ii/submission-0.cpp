class Solution {
private:
    string removeDupes(const string& s, int k){
        int r = 0, insert = 0, n = s.size();
        string res;

        while(r < n){
            res.push_back(s[r]);
            int i = 0;
            while(r + i < n && i < k){
                if(s[r] != s[r + i]) break;
                i++;
            }

            if(r + i == r + k){
                res.pop_back();
                r += i;
            }else{
                r++;
            }
        }

        return res;
    }
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n < k) return s;
        for(int i = 0; i < n / k; ++i){
            s = removeDupes(s, k);
        }
        return s;
    }
};