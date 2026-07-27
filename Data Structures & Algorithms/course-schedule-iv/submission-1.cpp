class Solution {
private:
    vector<vector<int>> memo;
    bool dfs(int u, int v, const unordered_map<int,unordered_set<int>>& dep){
        if(memo[u][v] != -1) return memo[u][v];

        auto it = dep.find(u);
        if(it == dep.end()) return memo[u][v] = false;
        if(dep.at(u).count(v)) return memo[u][v] = true;
        for(int d : dep.at(u)){
            if(dfs(d, v, dep)) return memo[u][v] = true;
        }
        return memo[u][v] = false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> dep;
        for(const auto& pre : prerequisites){
            dep[pre[0]].insert(pre[1]);
        }

        memo.resize(101, vector<int>(101, -1));
        int n = queries.size();
        vector<bool> res(n, false);
        for(int i = 0; i < n; ++i){
            vector<int> curr = queries[i];
            int u = curr[0], v = curr[1];
            res[i] = dfs(u, v, dep);
        }

        return res;
    }
};