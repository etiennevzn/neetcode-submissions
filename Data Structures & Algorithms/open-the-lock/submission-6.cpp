class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        int res = 0;
        unordered_set<string> visited = unordered_set<string>(deadends.begin(), deadends.end());;
        if(visited.count("0000")) return -1;
        if(target == "0000") return 0;

        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                string curr = q.front();
                q.pop();
                if(curr == target) return res;

                for(int j = 0; j < 4; ++j){
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