class Solution {
private:
    bool bfs(int numCourse, vector<vector<int>>& prerequisites, unordered_set<int>& path){
        if(path.count(numCourse)) return false;

        path.insert(numCourse);
        for(vector<int>& n : prerequisites){
            if(n[0] == numCourse){
                if(!bfs(n[1], prerequisites, path)) return false;
            }
        }
        path.erase(numCourse);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; ++i){
            unordered_set<int> pathNode;
            if(!bfs(i, prerequisites, pathNode)) return false;
        }
        return true;
    }
};
