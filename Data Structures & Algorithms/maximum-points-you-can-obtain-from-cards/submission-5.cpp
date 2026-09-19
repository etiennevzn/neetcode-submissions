class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int wSize = n - k;
        
        if(wSize == 0) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        int wSum = 0, minSum = INT_MAX, cardSum = 0;
        for(int r = 0; r < n; ++r){
            cardSum += cardPoints[r];
            wSum += cardPoints[r];
            if(r >= wSize - 1){
                minSum = min(minSum, wSum);
                wSum -= cardPoints[r - wSize + 1];
            }
        }

        return cardSum - minSum;
    }
};