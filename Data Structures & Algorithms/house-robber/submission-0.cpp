class Solution {
private:
    int dfs(vector<int>& nums, vector<bool>& visited){
        int maxi = -1;
        int maxIdx = -1;
        for(size_t i = 0; i < visited.size(); ++i){
            if(!visited[i]){
                if(nums[i] > maxi) {
                    maxi = nums[i];
                    maxIdx = i;
                }
            }
        }
        if(maxIdx == -1) return 0;
        visited[maxIdx] = true;
        bool neighborRight = false, neighborLeft = false;
        if(maxIdx + 1 < visited.size() && !visited[maxIdx + 1]) { visited[maxIdx+1] = true; neighborRight = true; }
        if(maxIdx - 1 >= 0 && !visited[maxIdx - 1]) { visited[maxIdx-1] = true; neighborLeft = true; }
        int result = nums[maxIdx] + dfs(nums, visited);
        visited[maxIdx] = false;
        if(neighborRight) visited[maxIdx+1] = false;
        if(neighborLeft) visited[maxIdx-1] = false;
        return result;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0;
        vector<bool> visited(nums.size(), false);
        int maxMoney = 0;
        for(int i = 0; i < nums.size(); ++i){
            visited[i] = true;
            bool neighborRight = false, neighborLeft = false;
            if(i + 1 < nums.size()) { visited[i+1] = true; neighborRight = true; }
            if(i - 1 >= 0) { visited[i-1] = true; neighborLeft = true; }
            maxMoney = max(maxMoney, nums[i] + dfs(nums, visited));
            fill(visited.begin(), visited.end(), false);
        }
        return maxMoney;
    }
};