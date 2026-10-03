class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int res = 0;
        int maxUnsatisfied = 0, windowSum = 0;

        for(int i = 0; i < n; ++i){
            res += (grumpy[i] == 0) ? customers[i] : 0;
            windowSum += (grumpy[i] == 1) ? customers[i] : 0;
            if(i >= minutes){
                windowSum -= (grumpy[i - minutes] == 1) ? customers[i - minutes] : 0;
            }
            maxUnsatisfied = max(maxUnsatisfied, windowSum);
        }

        return res + maxUnsatisfied;
    }
};