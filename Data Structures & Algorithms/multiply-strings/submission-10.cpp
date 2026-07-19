class Solution {
private:
    string add(string& num1, string& num2){
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        string res = "";
        while(i >= 0 || j >= 0){
            int digit1 = i < 0 ? 0 : num1[i--] - '0';
            int digit2 = j < 0 ? 0 : num2[j--] - '0';

            int tmp = digit1 + digit2 + carry;
            carry = tmp / 10;
            tmp %= 10;
            
            res.push_back(tmp + '0');
        }

        if(carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        if(num2.size() > num1.size()){
            swap(num1, num2);
        }
        string res = "";
        
        for(int j = num2.size() - 1; j >= 0; --j){
            string tmpRes = "";
            int carry = 0;
            for(int i = num1.size() - 1; i >= 0; --i){
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int tmp = digit1 * digit2 + carry;
                carry = tmp / 10;
                tmp %= 10;
                tmpRes.push_back(tmp + '0');
            }
            if(carry) tmpRes.push_back(carry + '0');
            reverse(tmpRes.begin(), tmpRes.end());
            tmpRes += string(num2.size() - 1 - j, '0');
            res = add(res, tmpRes);
        }

        return res;
    }
};
