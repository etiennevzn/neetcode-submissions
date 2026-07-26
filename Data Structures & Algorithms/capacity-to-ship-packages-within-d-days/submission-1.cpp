class Solution {
private:
    int numShipDays(int capacity, vector<int>& weights){
        int res = 0, tmp = capacity;
        for(int i = 0; i < weights.size(); ++i){
            if(i == weights.size() - 1){
                if(tmp - weights[i] < 0) res++;
                res++;
                continue;
            }
            if(tmp - weights[i] > 0){
                tmp -= weights[i];
            }else{
                res++;
                if(tmp - weights[i] == 0){
                    tmp = capacity;
                }else{
                    tmp = capacity - weights[i];
                }
            }
        } 
        return res;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);
        
        if(days == weights.size()) return minCap;

        while(minCap < maxCap){
            int m = minCap + (maxCap - minCap) / 2;
            int numDays = numShipDays(m, weights);

            if(numDays <= days){
                maxCap = m;
            }else{
                minCap = m + 1;
            }
        }

        return minCap;
    }
};