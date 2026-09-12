class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prevLine = triangle[n - 1];

        for(int i = n - 2; i >= 0; --i){
            vector<int> curLine = triangle[i];
            for(int j = 0; j < curLine.size(); ++j){
                curLine[j] += min(prevLine[j], prevLine[j+1]);
            }
            prevLine = curLine;
        }
        return prevLine[0];
    }
};