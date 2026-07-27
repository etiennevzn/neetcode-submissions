class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;
        int res = 0;

        unordered_set<string> begin = {"0000"}, end = {target};

        while(!begin.empty() && !end.empty()){
            res++;
            if(begin.size() > end.size()) swap(begin, end);
            unordered_set<string> tmp;
            for(string lock : begin){
                for(int i = 0; i < 4; ++i){
                    for(int dir : {-1, 1}){
                        string newLock = lock;
                        newLock[i] = ((lock[i] - '0' + dir + 10) % 10) + '0';
                        if(end.count(newLock)) return res;
                        if(visit.count(newLock)) continue;
                        tmp.insert(newLock);
                        visit.insert(newLock);
                    }
                }
            }
            begin = tmp;
        }

        return -1;
    }
};