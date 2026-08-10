class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int prevSign = 0, res = 1, cur = 0;
        for(int i = 0; i < arr.size() - 1; ++i){
            if(arr[i] > arr[i + 1] && prevSign != 1){
                cur++;
                prevSign = 1;
                res = max(res, cur + 1);
            }else if(arr[i] < arr[i + 1] && prevSign != -1){
                cur++;
                prevSign = -1;
                res = max(res, cur + 1);
            }else{
                cur = 0;
                prevSign = 0;
                if(arr[i] != arr[i + 1]) i--;
            }
        }
        return res;
    }
};