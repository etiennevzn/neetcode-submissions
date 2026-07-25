class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());

        while(l < r){
            res++;
            if(people[l] + people[r] <= limit){
                l++;
                r--;
            }else{
                r--;
            }
        }

        return l == r ? res + 1 : res;
    }
};