class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));

        for(const auto& pre : prerequisites){
            adj[pre[0]][pre[1]] = true;
        }

        for(int i = 0; i < numCourses; ++i){
            for(int j = 0; j < numCourses; ++j){
                for(int k = 0; k < numCourses; ++k){
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                }
            }
        }

        vector<bool> res;
        for(const auto& q : queries){
            res.push_back(adj[q[0]][q[1]]);
        }

        return res;
    }
};