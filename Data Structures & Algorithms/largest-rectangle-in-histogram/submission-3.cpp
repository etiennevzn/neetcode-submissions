class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int,int>> s;
        int n = heights.size();

        for(int i = 0; i <= n; ++i){
            while(!s.empty() && (i == n || s.top().second > heights[i])){
                int height = s.top().second;
                s.pop();
                int width = s.empty() ? i : i - s.top().first - 1;
                maxArea = max(maxArea, height*width);
            }

            if(i != n) s.push({i, heights[i]});
        }

        return maxArea;
    }
};
