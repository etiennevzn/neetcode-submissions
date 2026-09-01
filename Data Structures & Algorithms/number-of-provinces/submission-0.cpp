//idées : DFS ou l'on parcourt tous les sommets s'ils ne sont pas dans le set visited ou DSU ou l'on réunit les sommets et on compte le nombre de components à la fin

class Solution {
private:
    unordered_set<int> visited;
    int n;

    void dfs(int i, vector<vector<int>>& isConnected){
        visited.insert(i);

        for(int j = 0; j < n; ++j){
            if(!visited.count(j) && isConnected[i][j]){
                dfs(j, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int res = 0;
        
        for(int i = 0; i < n; ++i){
            if(!visited.count(i)){
                res++;
                dfs(i, isConnected);
            }
        }

        return res;
    }
};