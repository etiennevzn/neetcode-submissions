class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int slow = n, fast = sumOfSquare(n);
        while(slow != fast){
            slow = sumOfSquare(slow);
            fast = sumOfSquare(sumOfSquare(fast));
        }
        return slow == 1;
    }

    int sumOfSquare(int n){
        int output = 0;
        while(n > 0){
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};
