class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int l = 0, r = x;

        int res = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            long long multi = 1LL * m * m;
            if(multi == x) return m;
            if(multi < x){
                res = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }

        return res;
    }
};