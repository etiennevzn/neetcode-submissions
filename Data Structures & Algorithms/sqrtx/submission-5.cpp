class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(true){
            if((long long) i * i == x) return i;
            if((long long) i * i > x) return i - 1;
            i++;
        }
    }
};