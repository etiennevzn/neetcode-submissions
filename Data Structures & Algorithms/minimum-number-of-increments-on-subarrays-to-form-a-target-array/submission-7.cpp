class Solution {
private:
    int numOperations(int begin, int end, int floorVal, vector<int>& target){
        if(begin > end) return 0;

        int minIdx = begin;
        for(int i = begin + 1; i <= end; ++i){
            if(target[i] < target[minIdx]) minIdx = i;
        }
        int minVal = target[minIdx];

        return (minVal - floorVal) + numOperations(minIdx + 1, end, minVal, target) + numOperations(begin, minIdx - 1, minVal, target); 
    }
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        return numOperations(0, n - 1, 0, target);
    }
};