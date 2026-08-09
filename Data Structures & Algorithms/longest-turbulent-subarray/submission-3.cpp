class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;

        int l = 0, r = 1, prevSign = 0, res = 1;
        while(r < n){
            if(arr[r] < arr[r - 1] && prevSign != -1){
                prevSign = -1;
                r++;
                res = max(res, r - l);
            }else if(arr[r] > arr[r - 1] && prevSign != 1){
                prevSign = 1;
                r++;
                res = max(res, r - l);
            }else{
                r = (arr[r] == arr[r - 1]) ? r + 1 : r;
                prevSign = 0;
                l = r - 1;
            }
        }

        return res;
    }
};