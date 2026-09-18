class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type1 = -1, type2 = -1;
        unordered_map<int, int> count;

        int r = 0, l = 0;
        int res = 0;
        while(r < fruits.size()){
            if(type1 == -1 || type2 == -1 || fruits[r] == type1 || fruits[r] == type2){
                count[fruits[r]]++;
                if(type1 == -1) type1 = fruits[r];
                else if(type2 == -1 && fruits[r] != type1) type2 = fruits[r];
                r++;
                res = max(res, r - l);
            }else{
                bool end = true;
                while(end && l < fruits.size()){
                    count[fruits[l]]--;
                    if(count[fruits[l]] == 0){
                        if(fruits[l] == type1) type1 = -1;
                        if(fruits[l] == type2) type2 = -1;
                        end = false;
                    }
                    l++;
                }
                if(type1 == -1) type1 = fruits[r];
                if(type2 == -1) type2 = fruits[r];
            }
        }

        return res;
    }
};