class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        int i = n - 1;
        while(carry > 0){
            if(i < 0){
                digits.insert(digits.begin(), carry);
                break;
            }
            if(digits[i] == 9){
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
