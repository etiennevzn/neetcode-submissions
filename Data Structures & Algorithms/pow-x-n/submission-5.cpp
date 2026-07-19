class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(n < 0) return 1 / myPow(x, -n);

        double half = myPow(x*x, n / 2);
        return (n % 2) ? x * half : half;
    }
};