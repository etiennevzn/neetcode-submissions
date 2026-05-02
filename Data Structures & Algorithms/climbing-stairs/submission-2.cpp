class Solution {
public:
    int climbStairs(int n) {
        int right = 0, left = 1, res = 0;
        for(int i = 0; i <= n; ++i){
            res = right + left;
            left = right; 
            right = res;
        }

        return res;
    }
};
