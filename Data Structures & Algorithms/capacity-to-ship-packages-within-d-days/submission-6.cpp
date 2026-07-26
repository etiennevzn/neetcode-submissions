class Solution {
private:
    int numShipDays(int capacity, vector<int>& weights){
        int res = 1, curCap = capacity;
        for(int w : weights){
            if(curCap - w < 0){
                res++;
                curCap = capacity;
            }
            curCap -= w;
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