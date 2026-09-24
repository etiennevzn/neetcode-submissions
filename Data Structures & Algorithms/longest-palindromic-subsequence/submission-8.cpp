class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> prevLine(n + 1, 0);
        vector<int> curLine(n + 1, 0);

        for(int l = n - 1; l >= 0; --l){
            fill(curLine.begin(), curLine.end(), 0);
            for(int r = l; r < n; ++r){
                if(r == l){
                    curLine[r] = 1;
                }else{
                    if(s[l] == s[r]){
                        curLine[r] = 2 + prevLine[r - 1];
                    }else{
                        curLine[r] = max(curLine[r - 1], prevLine[r]);
                    }
                }
            }
            prevLine = curLine;
        }
        return curLine[n - 1];
    }
};