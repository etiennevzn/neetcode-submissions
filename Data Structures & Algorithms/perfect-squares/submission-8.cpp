class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> seen;
        int count = 0;
        queue<int> q;
        q.push(0);
        seen.insert(0);

        while(!q.empty()){
            int qSize = q.size();
            count++;
            for(int i = 0; i < qSize; ++i){
                int cur = q.front(); 
                q.pop();
                for(int i = 0; cur + i * i <= n; ++i){
                    if(cur + i * i == n) return count;
                    if(seen.insert(cur + i * i).second) q.push(cur + i * i);
                }
            }
        }

        return n;
    }
};