class Solution {
private:
    unordered_set<int> visited;

    void dfs(int cur, unordered_map<int, vector<int>>& graph){
        for(int nei : graph[cur]){
            if(visited.insert(nei).second){
                dfs(nei, graph);
            }
        }
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> graph;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(gcd(nums[i], nums[j]) > 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        dfs(0, graph);

        return visited.size() == nums.size();
    }
};