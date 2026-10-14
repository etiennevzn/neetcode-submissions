class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> prefixSum(arr.size() + 1);

        int res = 0;
        for(size_t i = 0; i < arr.size(); ++i){
            prefixSum[i + 1] = prefixSum[i] + arr[i];
            if(i >= k - 1){
                if(prefixSum[i + 1] - prefixSum[i - k + 1] >= threshold * k) res++;
            }
        }

        return res;
    }
};