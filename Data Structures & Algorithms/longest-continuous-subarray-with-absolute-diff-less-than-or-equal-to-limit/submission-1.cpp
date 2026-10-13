class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        priority_queue<pair<int,int>> maxHeap;
        int l = 0;
        int res = 0;

        for(size_t r = 0; r < nums.size(); ++r){
            minHeap.emplace(nums[r], r);
            maxHeap.emplace(nums[r], r);

            while(!maxHeap.empty() && !minHeap.empty() && abs(maxHeap.top().first - minHeap.top().first) > limit){
                l++;
                while(!maxHeap.empty() && maxHeap.top().second < l) maxHeap.pop();
                while(!minHeap.empty() && minHeap.top().second < l) minHeap.pop();
            }

            res = max(res, (int)r - l + 1);
        }

        return res;
    }
};