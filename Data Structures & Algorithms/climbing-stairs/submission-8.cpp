class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        for(int i = 2; i <= n; ++i){
            int temp = one;
            one += two;
            two = temp;
        }

        return one;
    }
};
