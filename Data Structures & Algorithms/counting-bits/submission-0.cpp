class Solution {
private:
    int numOnes(uint16_t num){
        int res = 0;
        while(num > 0){
            num &= num - 1;
            res++;
        }
        return res; 
    }
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i){
            res.push_back(numOnes((uint16_t)i));
        }
        return res;
    }
};
