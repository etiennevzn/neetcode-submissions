class Solution {
private:
    vector<int> ans;
    vector<int> countLabels;

    void dfs(int cur, int parent, const string& labels, const vector<vector<int>>& graph){
        int prevCount = countLabels[labels[cur] - 'a'];
        countLabels[labels[cur] - 'a']++;

        for(int nei : graph[cur]){
            if(nei == parent) continue;
            dfs(nei, cur, labels, graph);
        }

        ans[cur] = countLabels[labels[cur] - 'a'] - prevCount;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n, 1);
        countLabels.assign(26, 0);

        vector<vector<int>> graph(n);
        for(const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, 0, labels, graph);

        return ans;
    }
};