class Solution {
public:
    string pushDominoes(string dominoes) {
        int lastRight = -1;
        bool reset = true;
        for(size_t i = 0; i < dominoes.size(); ++i){
            if(dominoes[i] == 'L'){
                if(lastRight == -1 || reset){
                    for(int j = i - 1; j >= 0; --j){
                        if(dominoes[j] == 'L') break;
                        dominoes[j] = 'L';
                    }
                }else{
                    int l = lastRight + 1, r = i - 1;
                    while(l < r){
                        dominoes[r--] = 'L';
                        dominoes[l++] = 'R';
                    }
                }
                reset = true;
            }else if(dominoes[i] == 'R'){
                if(lastRight != -1 && !reset){
                    for(int j = lastRight + 1; j < i; ++j) dominoes[j] = 'R';
                }
                lastRight = i;
                reset = false;
            }
        }

        if(!reset){
            for(size_t i = lastRight + 1; i < dominoes.size(); ++i){
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};
