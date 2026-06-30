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
        for(const vector<int>& row : matrix){
            if(binarySearch(row, target)) return true;
        }
        return false;
    }
};
