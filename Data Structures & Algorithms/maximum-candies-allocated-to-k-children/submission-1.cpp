class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0; 
        int maxPile = 0;
        for(int c : candies){
            total += c;
            maxPile = max(maxPile, c);
        }

        if(total < k) return 0;

        int l = 1, r = maxPile, ans = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            long long cnt = 0;

            for(int c : candies){
                cnt += c / m;
            }

            if(cnt >= k){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }

        return ans;
    }
};
