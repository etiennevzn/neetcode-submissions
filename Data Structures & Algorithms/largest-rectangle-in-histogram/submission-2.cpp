class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<pair<int,int>> s;

        for(int i = 0; i < heights.size(); ++i){
            int curIdx = i;
            while(!s.empty() && s.top().second > heights[i]){
                pair<int,int> cur = s.top();
                s.pop();
                curIdx = cur.first;
                maxi = max(maxi, (i - cur.first)*cur.second);
            }

            s.push({curIdx, heights[i]});
        }

        while(!s.empty()){
            pair<int,int> cur = s.top();
            s.pop();
            maxi = max(maxi, (int)(heights.size() - cur.first)*cur.second);
        }

        return maxi;
    }
};
