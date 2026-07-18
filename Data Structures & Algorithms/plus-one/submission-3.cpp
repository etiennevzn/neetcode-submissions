class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 1;
        int i = n;
        while(carry > 0){
            if(i < 0){
                digits.insert(digits.begin(), carry);
                break;
            }
            if(digits[i] == 9){
                carry = 1;
                digits[i] = 0;
            }else{
                digits[i] += carry;
                carry = 0;
            }
            i--;
        }

        return digits;
    }
};
