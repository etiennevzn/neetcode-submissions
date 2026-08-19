class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int maxVisited = 0;
        q.push(0);
        int n = s.size();

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            int start = max(curr + minJump, maxVisited + 1);
            int end = min(curr + maxJump, n - 1);

            for(int arrival = start; arrival <= end; ++arrival){
                if(s[arrival] == '0'){
                    if(arrival == n - 1) return true;
                    q.push(arrival);
                }
            }

            maxVisited = max(maxVisited, end);
        }

        return false;
    }
};