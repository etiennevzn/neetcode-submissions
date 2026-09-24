class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row, newRow;

        for(int i = 0; i <= rowIndex; ++i){
            newRow.resize(i + 1, 1);
            newRow[0] = newRow[i] = 1;
            for(int j = 1; j < i; ++j){
                newRow[j] = row[j - 1] + row[j];
            }
            row = newRow;
        }

        return row;
    }
};