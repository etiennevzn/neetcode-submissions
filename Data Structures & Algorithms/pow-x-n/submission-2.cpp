class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int nor = n;
        n = abs(n);
        while(n > 0){
            if(n % 2 == 1){
                res *= x;
            }

            x *= x;
            n /= 2;
        }

        return nor > 0 ? res : 1.0 / res;
    }
};