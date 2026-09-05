class Solution {
public:
    int minSwaps(string s) {
        int unbalance = 0, maxUnbalance = 0;
        for(const char& c : s){
            if(c == ']'){
                unbalance++;
            }else{
                unbalance--;
            }
            maxUnbalance = max(maxUnbalance, unbalance);
        }

        return (maxUnbalance + 1) / 2;
    }
};