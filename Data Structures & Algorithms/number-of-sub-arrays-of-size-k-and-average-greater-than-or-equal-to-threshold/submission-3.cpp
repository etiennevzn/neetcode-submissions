class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int windowSum = 0, res = 0;

        for(size_t r = 0; r < arr.size(); ++r){
            windowSum += arr[r];
            if(r >= k - 1){
                if(windowSum >= threshold * k) res++;
                windowSum -= arr[r - k + 1];
            }
        }

        return res;
    }
};