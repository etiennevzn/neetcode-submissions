class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        int l = 0, r = 0;

        while(r < nums.size()){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if(q.front() < l) q.pop_front();

            if(r >= k-1){
                res.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }

        return res;
    }
};
