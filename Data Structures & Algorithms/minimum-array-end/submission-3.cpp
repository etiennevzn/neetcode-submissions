class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = 0;
        n -= 1;

        vector<int> x_bin(64, 0);
        vector<int> n_bin(64, 0);

        for(int i = 0; i < 32; ++i){
            x_bin[i] = (x >> i) & 1;
            n_bin[i] = (n >> i) & 1;
        }

        int i = 0, j = 0;
        while(i < x_bin.size() && j < n_bin.size()){
            if(x_bin[i]){
                i++;
                continue;
            }

            x_bin[i++] = n_bin[j++];
        }

        while(j < n_bin.size()) x_bin.push_back(n_bin[j++]);

        for(int i = 0; i < x_bin.size(); ++i){
            res |= (long long)x_bin[i] << i;
        }

        return res;
    }
};