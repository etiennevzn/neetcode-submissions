class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);

        int moves = 0, balls = 0;
        for(int i = 0; i < n; ++i){
            res[i] += moves + balls;
            moves += balls;
            balls += boxes[i] - '0';
        }

        moves = 0, balls = 0;
        for(int i = n - 1; i >= 0; --i){
            res[i] += moves + balls;
            moves += balls;
            balls += boxes[i] - '0';
        }

        return res;
    }
};