class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while(!seen.count(n)){
            seen.insert(n);
            int tmp = 0;
            while(n > 0){
                int digit = n % 10;
                tmp += digit * digit;
                n /= 10;
            }
            if(tmp == 1) return true;
            n = tmp;
        }
        return false;
    }
};
