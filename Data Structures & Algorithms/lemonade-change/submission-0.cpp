class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> changeCount;

        for(int bill : bills){
            changeCount[bill]++;
            if(bill > 5){
                int changeNeeded = bill - 5;
                while(changeNeeded > 0){
                    if(changeNeeded >= 10 && changeCount[10]){
                        changeNeeded -= 10;
                        changeCount[10]--;
                    }else if(changeNeeded >= 5 && changeCount[5]){
                        changeNeeded -= 5;
                        changeCount[5]--;
                    }else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};