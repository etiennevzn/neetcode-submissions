class Solution {
private:
bool canEat(vector<int>& piles, int h, int k){
    long counter = 0;
    for(int pile : piles){
        counter += (pile + k - 1) / k;
    }
    return counter <= h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        if(h == piles.size()) return maxi;
        int res = maxi;

        int l = 1, r = maxi;
        while(l <= r){
            int m = l + (r - l)/2;
            if(canEat(piles, h, m)){
                res = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        return res;
    }
};
