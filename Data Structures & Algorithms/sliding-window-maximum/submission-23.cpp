class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int,int>> q;
        int r = 0;

        while(r < nums.size()){
            while(!q.empty() && q.back().first < nums[r]){
                q.pop_back();
            }
            q.push_back({nums[r],r});
            if(q.front().second <= r-k) q.pop_front();
            if(r >= k-1){
                res.push_back(q.front().first);
            }
            r++;
        }

        return res;
    }
};
