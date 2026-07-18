class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        seen.insert(n);
        while(n != 1){
            string num = to_string(n);
            n = 0;
            for(char c : num){
                n += pow(c - '0', 2);
            }
            if(!seen.insert(n).second) return false;
        }
        return true;
    }
};
