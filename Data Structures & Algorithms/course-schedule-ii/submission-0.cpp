class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> depMap;
        vector<int> indegree(numCourses, 0);

        for(const auto& pre : prerequisites){
            depMap[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        vector<int> res;
        for(int c = 0; c < numCourses; ++c){
            if(!indegree[c]) q.push(c);
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for(int c : depMap[cur]){
                indegree[c]--;
                if(!indegree[c]) q.push(c);
            }
        }
        

        return res.size() == numCourses ? res : vector<int>();
    }
};
