class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        int n = a.size(), m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;
        int i = 0;
        while(i < min(n, m)){
            if(a[i] == '1'){
                if(b[i] == '1'){
                    res.push_back(carry);
                    carry = '1';
                }else{
                    if(carry == '1'){
                        res.push_back('0');
                    }else{
                        res.push_back('1');
                    }
                }
            }else{
                if(b[i] == '1'){
                    if(carry == '1'){
                        res.push_back('0');
                    }else{
                        res.push_back('1');
                    }
                }else{
                    res.push_back(carry);
                    carry = '0';
                }
            }
            i++;
        }

        while(i < n){
            if(a[i] == '1'){
                if(carry == '1'){
                    res.push_back('0');
                }else{
                    res.push_back('1');
                }
            }else{
                res.push_back(carry);
                carry = '0';
            }
            i++;
        }

        while(i < m){
            if(b[i] == '1'){
                if(carry == '1'){
                    res.push_back('0');
                }else{
                    res.push_back('1');
                }
            }else{
                res.push_back(carry);
                carry = '0';
            }
            i++;
        }

        if(carry == '1') res.push_back('1');
        reverse(res.begin(), res.end());
        return res; 
    }
};