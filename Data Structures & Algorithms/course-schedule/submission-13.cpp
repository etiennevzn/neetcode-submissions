class Solution {
private:
    unordered_map<int, vector<int>> preMap;
    set<int> visiting;

    bool dfs(int c){
        if(visiting.count(c)) return false;
        visiting.insert(c);
        for(int pre : preMap[c]){
            if(!dfs(pre)) return false;
        }
        preMap[c].clear();
        visiting.erase(c);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(const auto& pre : prerequisites){
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int c = 0; c < numCourses; ++c){
            if(!dfs(c)) return false;
        }

        return true;
    }
};
