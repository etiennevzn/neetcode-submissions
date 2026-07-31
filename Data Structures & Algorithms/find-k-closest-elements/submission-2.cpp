class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closestIdx = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(abs(arr[i] - x) < abs(arr[closestIdx] - x)){
                closestIdx = i;
            }
        }

        int l = closestIdx, r = closestIdx;
        while(r - l + 1 < k){
            if(l - 1 >= 0 && abs(arr[l - 1] - x) <= abs(arr[r + 1] - x)){
                l--;
            }else if(r + 1 < arr.size()){
                r++;
            }
        }

        vector<int> res;
        for(int i = l; i <= r; ++i){
            res.push_back(arr[i]);
        }

        return res;
    }
};