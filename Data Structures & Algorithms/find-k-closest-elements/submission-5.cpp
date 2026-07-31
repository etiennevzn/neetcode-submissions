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
            if(l == 0){
                r++;
            }else if(r == arr.size() - 1){
                l--;
            }else if(abs(arr[l - 1] - x) <= abs(arr[r + 1] - x)){
                l--;
            }else{
                r++;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};