class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int power = abs(n);
        while(power > 0){
            if(power % 2 == 1){
                res *= x;
            }

            x *= x;
            power /= 2;
        }

        return n > 0 ? res : 1 / res;
    }
};