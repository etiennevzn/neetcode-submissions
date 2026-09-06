class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int curSum = 0, countOdd = 0, countEven = 0, mod = 1e9 + 7, res = 0;

        for(int i = 0; i < arr.size(); ++i){
            curSum += arr[i];
            if(curSum % 2){
                countOdd++;
                res = (res + 1 + countEven) % mod;
            }else{
                countEven++;
                res = (res + countOdd) % mod;
            }
        }

        return res;
    }
};