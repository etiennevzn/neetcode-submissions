class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) return 1 / myPow(x, -n);

        double half = myPow(x*x, n / 2);
        if(n % 2) return x * half;
        return half;
    }
};