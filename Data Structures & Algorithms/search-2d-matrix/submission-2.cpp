class Solution {
private:
    bool binarySearch(const vector<int>& row, int target){
        int l = 0, r = row.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(target < row[m]){
                r = m - 1;
            }else if(target > row[m]){
                l = m + 1;
            }else{
                return true;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0, b = matrix.size()-1;
        int n = matrix[0].size()-1;
        while(t <= b){
            int m = t + (b - t)/2;
            if(target < matrix[m][0]){
                b = m - 1;
            }else if(target > matrix[m][n]){
                t = m + 1;
            }else{
                return binarySearch(matrix[m], target);
            }
        }
        return false;
    }
};
