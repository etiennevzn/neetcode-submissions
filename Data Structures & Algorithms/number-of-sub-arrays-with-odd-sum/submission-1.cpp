class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            long long subSum = 0;
            for(int j = i; j < n; ++j){
                subSum += arr[j];
                if(subSum % 2) res++;
            }
        }

        int mod = 1000000007;
        return res % mod;
    }
};