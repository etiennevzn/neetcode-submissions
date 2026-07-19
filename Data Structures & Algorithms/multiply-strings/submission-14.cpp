class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        if(n > m){
            swap(num1, num2);
            swap(n, m);
        }
        
        vector<int> tmp(n + m);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < m; ++i){
                int res = (num2[j] - '0') * (num1[i] - '0') + tmp[i + j];
                tmp[i + j] = res % 10;
                tmp[i + j + 1] += res / 10; 
            }
        }

        string res;
        int i = m + n - 1;
        while(i >= 0 && tmp[i] == 0) i--;
        while(i >= 0) res.push_back(tmp[i--] + '0');
        return res;
    }
};
