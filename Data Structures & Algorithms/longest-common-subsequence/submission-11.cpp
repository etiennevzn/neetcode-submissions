class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> nextLine(m + 1, 0);

        for(int i = n - 1; i >= 0; --i){
            vector<int> curLine(m + 1, 0);

            for(int j = m - 1; j >= 0; --j){
                if(text1[i] == text2[j]){
                    curLine[j] = 1 + nextLine[j + 1];
                }else{
                    curLine[j] = max(nextLine[j], curLine[j + 1]);
                }
            }

            nextLine = curLine;
        }

        return nextLine[0];
    }
};
