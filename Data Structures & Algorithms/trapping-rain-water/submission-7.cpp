class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxHeightLeft(n);
        vector<int> maxHeightRight(n);
        int res = 0;

        int maxi = 0;
        for(int i = 0; i < n; ++i){
            maxHeightLeft[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        maxi = 0;
        for(int i = n - 1; i >= 0; --i){
            maxHeightRight[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        for(int i = 0; i < n; ++i){
            if(maxHeightLeft[i] != 0 && maxHeightRight[i] != 0){
                res += max(0, min(maxHeightLeft[i], maxHeightRight[i]) - height[i]);
            }
        }

        return res;
    }
};
