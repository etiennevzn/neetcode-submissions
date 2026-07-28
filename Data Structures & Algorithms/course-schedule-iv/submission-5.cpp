class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        queue<int> q;
        unordered_map<int, unordered_set<int>> preMap;
        unordered_map<int, unordered_set<int>> adj;
        vector<int> indegree(numCourses);

        for(const auto& pre : prerequisites){
            adj[pre[0]].insert(pre[1]);
            indegree[pre[1]]++;
        }

        for(int i = 0; i < numCourses; ++i){
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(!adj.count(curr)) continue;
            for(int next : adj[curr]){
                preMap[next].insert(curr);
                preMap[next].insert(preMap[curr].begin(), preMap[curr].end());
                indegree[next]--;
                if(!indegree[next]) q.push(next);
            }
        }

        vector<bool> res;
        for(const auto& q : queries){
            res.push_back(preMap[q[1]].count(q[0]));
        }

        return res;
    }
};