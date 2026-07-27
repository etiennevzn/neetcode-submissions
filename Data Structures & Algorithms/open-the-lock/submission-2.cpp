class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        int res = 0;
        set<string> visited;
        set<string> deadendSet = set<string>(deadends.begin(), deadends.end());

        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                string curr = q.front();
                q.pop();
                if(curr == target) return res;
                if(deadendSet.count(curr)) continue;

                for(int j = 0; j < curr.size(); ++j){
                    string newNum = curr;
                    newNum[j] = ((curr[j] - '0' + 1) % 10) + '0';
                    if(visited.insert(newNum).second) q.push(newNum);
                    
                    newNum = curr;
                    newNum[j] = ((curr[j] - '0' + 9) % 10) + '0';
                    if(visited.insert(newNum).second) q.push(newNum);
                }
            }
            res++;
        }

        return -1;
    }
};