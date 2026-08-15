class Solution {
public:
    long long minEnd(int n, int x) {
        long long cur = x;
        for(int i = 1; i < n; ++i){
            cur += 1;
            cur |= x;
        }
        return cur;
    }
};