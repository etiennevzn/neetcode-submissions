class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> dependencyMap;
        vector<int> indegree(numCourses, 0);
        queue<int> courseQueue;

        for(const auto& pre : prerequisites){
            dependencyMap[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int c = 0; c < numCourses; ++c){
            if(!indegree[c]) courseQueue.push(c);
        }

        int processed = 0;
        while(!courseQueue.empty()){
            int cur = courseQueue.front();
            courseQueue.pop();
            processed++;

            for(int dep : dependencyMap[cur]){
                indegree[dep]--;
                if(!indegree[dep]) courseQueue.push(dep);
            }
        }

        return processed == numCourses;
    }
};
