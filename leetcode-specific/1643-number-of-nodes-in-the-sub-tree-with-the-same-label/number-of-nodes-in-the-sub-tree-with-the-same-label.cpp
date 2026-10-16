class Solution {
private:
    vector<int> ans;

    vector<int> dfs(int cur, int parent, const string& labels, const vector<vector<int>>& graph){
        vector<int> countLabels(26, 0);
        countLabels[labels[cur] - 'a']++;

        for(int nei : graph[cur]){
            if(nei == parent) continue;
            vector<int> subLabels = dfs(nei, cur, labels, graph);
            for(int i = 0; i < 26; ++i) countLabels[i] += subLabels[i];
        }

        ans[cur] = countLabels[labels[cur] - 'a'];
        return countLabels;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n, 1);

        vector<vector<int>> graph(n);
        for(const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, 0, labels, graph);

        return ans;
    }
};