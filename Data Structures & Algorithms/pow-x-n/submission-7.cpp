class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;

        long long power = n;
        if(power < 0) power = -power;
        
        double res = 1;
        while(power > 0){
            if(power % 2){
                res *= x;
                power--;
            }

            x *= x;
            power /=2;
        }

        return (n < 0) ? 1 / res : res;
    }
};