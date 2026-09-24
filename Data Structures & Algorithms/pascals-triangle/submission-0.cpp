class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows == 1) return res;
        res.push_back({1, 1});
        if(numRows == 2) return res;

        for(int i = 3; i <= numRows; ++i){
            vector<int> newLine(res.back().size() + 1, 1);
            for(int j = 1; j < newLine.size() - 1; ++j){
                newLine[j] = res.back()[j - 1] + res.back()[j];
            }
            res.push_back(newLine);
        }

        return res;
    }
};