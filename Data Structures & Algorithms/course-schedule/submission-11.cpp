class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<bool> finished(numCourses, false);

        for(const vector<int>& pre : prerequisites){
            indegree[pre[0]]++;
        }

        queue<int> courseQueue;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0) courseQueue.push(i);
        }

        while(!courseQueue.empty()){
            int courseNum = courseQueue.front();
            courseQueue.pop();
            finished[courseNum] = true;

            for(const vector<int>& pre : prerequisites){
                if(pre[1] == courseNum){
                    indegree[pre[0]]--;
                    if(indegree[pre[0]] == 0) courseQueue.push(pre[0]);
                }
            }
        }

        return find(finished.begin(), finished.end(), false) == finished.end();
    }
};
