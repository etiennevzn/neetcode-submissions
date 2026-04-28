class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(const vector<int>& pre : prerequisites){
            indegree[pre[0]]++;
            graph[pre[1]].push_back(pre[0]);
        }

        queue<int> courseQueue;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0) courseQueue.push(i);
        }

        int count = 0;
        while(!courseQueue.empty()){
            int courseNum = courseQueue.front();
            courseQueue.pop();
            count++;

            for(int suc : graph[courseNum]){
                indegree[suc]--;
                if(indegree[suc] == 0) courseQueue.push(suc);
            }
        }

        return count == numCourses;
    }
};
