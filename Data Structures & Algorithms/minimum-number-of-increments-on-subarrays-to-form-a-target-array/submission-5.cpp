class Solution {
private:
    vector<vector<int>> memo;
    int numOperations(int begin, int end, int floorVal, vector<int>& target){
        if(begin > end) return 0;
        if(memo[begin][end] != -1) return memo[begin][end];

        int minIdx = begin;
        for(int i = begin + 1; i <= end; ++i){
            if(target[i] < target[minIdx]) minIdx = i;
        }
        int minVal = target[minIdx];
        
        return memo[begin][end] = (minVal - floorVal) + numOperations(minIdx + 1, end, minVal, target) + numOperations(begin, minIdx - 1, minVal, target); 
    }
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        memo.assign(n, vector<int>(n, -1));
        return numOperations(0, n - 1, 0, target);
    }
};