class Solution {
private:  
    vector<vector<int>> memo;
    int dfs(int l, int r, const vector<int>& cardPoints, int k){
        if(k == 0) return 0;
        if(memo[l][r] != -1) return memo[l][r];

        int takeBegin = cardPoints[l] + dfs(l + 1, r, cardPoints, k - 1);
        int takeEnd = cardPoints[r] + dfs(l, r - 1, cardPoints, k - 1);

        return memo[l][r] = max(takeBegin, takeEnd);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k == cardPoints.size()) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        memo.resize(cardPoints.size(), vector<int>(cardPoints.size(), -1));
        
        return dfs(0, cardPoints.size() - 1, cardPoints, k);
    }
};