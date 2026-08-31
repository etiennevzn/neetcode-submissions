class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>> count(k, vector<int>(2));
        for(int i = 0; i < k; ++i){
            for(const char& c : strs[i]){
                count[i][c - '0']++;
            }
        }

        vector<vector<int>> line(m + 1, vector<int>(n + 1, 0));

        for(int i = k - 1; i >= 0; --i){
            vector<vector<int>> newLine(m + 1, vector<int>(n + 1, 0));
            for(int j = 0; j <= m; ++j){
                for(int l = 0; l <= n; ++l){
                    int skip = line[j][l];

                    int take = 0;
                    if(count[i][0] <= j && count[i][1] <= l){
                        take = 1 + line[j - count[i][0]][l - count[i][1]];
                    }

                    newLine[j][l] = max(skip, take);
                }
            }
            line = newLine;
        }

        return line[m][n];
    }
};