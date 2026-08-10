class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int prevSign = 0, res = 0, cur = 0;
        for(int i = 0; i < arr.size() - 1; ++i){
            if(arr[i] > arr[i + 1]){
                cur = prevSign != 1 ? cur + 1 : 1;
                prevSign = 1;
            }else if(arr[i] < arr[i + 1]){
                cur = prevSign != -1 ? cur + 1 : 1;
                prevSign = -1;
            }else{
                cur = 0;
                prevSign = 0;
            }

            res = max(res, cur);
        }
        return res + 1;
    }
};