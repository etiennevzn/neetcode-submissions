class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxVol = 0;

        while(l < r){
            int volume = (r-l) * min(heights[r], heights[l]);
            maxVol = volume > maxVol ? volume : maxVol;

            if(min(heights[r], heights[l]) == heights[l]){
                l++;
            }else{
                r--;
            }
        }

        return maxVol;
    }
};
