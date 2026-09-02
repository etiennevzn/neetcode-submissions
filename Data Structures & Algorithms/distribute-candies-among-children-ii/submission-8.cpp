class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        int maxA = min(n, limit);
        for(int a = 0; a <= maxA; ++a){
            int rem = n - a;
            if(rem <= 2 * limit){
                int hi = min(rem, limit);
                int lo = max(0, rem - limit);
                res += (long long)(hi - lo + 1);
            }
        }

        return res;
    }
};