class Solution {
private:
    int res = 0;
    void dfs(int i, int prevSign, int cur, const vector<int>& arr){
        if(i == arr.size()) return;

        if(arr[i] < arr[i - 1] && prevSign != -1){
            cur++;
            dfs(i + 1, -1, cur, arr);
        }else if(arr[i] > arr[i - 1] && prevSign != 1){
            cur++;
            dfs(i + 1, 1, cur, arr);
        }else{
            i = (arr[i] == arr[i - 1]) ? i + 1 : i;
            cur = 0;
            dfs(i, 0, cur, arr);
        }

        res = max(res, cur);
    }

public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        dfs(1, 0, 0, arr);
        return res + 1;
    }
};