class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 0;
        digits[n] += 1;
        if(digits[n] == 10){
            carry = 1;
            digits[n] -= 10;
        }

        int i = n - 1;
        while(carry > 0){
            if(i < 0){
                digits.insert(digits.begin(), carry);
                break;
            }
            digits[i] += carry;
            if(digits[i] == 10){
                carry = 1;
                digits[i] -= 10;
            }else{
                carry = 0;
            }
            i--;
        }

        return digits;
    }
};
