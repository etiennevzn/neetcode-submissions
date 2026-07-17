class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);
        if(sumCost > sumGas) return -1;

        int total = 0, res = 0;
        for(int i = 0; i < gas.size(); ++i){
            total += gas[i] - cost[i];
            if(total < 0){
                res = i + 1;
                total = 0;
            }
        }
        return res;
    }
};
