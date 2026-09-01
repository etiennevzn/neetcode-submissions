class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;

        queue<int> toTreat;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                res++;
                toTreat.push(i);
                visited[i] = true;

                while(!toTreat.empty()){
                    int curr = toTreat.front();
                    toTreat.pop();
                    for(int j = 0; j < n; ++j){
                        if(!visited[j] && isConnected[curr][j]){
                            toTreat.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }

        return res;
    }
};