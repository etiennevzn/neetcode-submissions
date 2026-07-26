class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> awaiting;

        for(int i = 0; i < tasks.size(); ++i){
            awaiting.push({tasks[i][0], tasks[i][1], i});
        }

        long long time = awaiting.top()[0];

        while(!awaiting.empty() || !available.empty()){
            while(!awaiting.empty() && awaiting.top()[0] <= time){
                vector<int> task = awaiting.top();
                awaiting.pop();
                available.push({task[1], task[2]});
            }

            if(!available.empty()){
                auto [pTime, idx] = available.top();
                available.pop();
                res.push_back(idx);
                time += pTime;
            }else{
                time = awaiting.top()[0];
            }
        }

        return res;
    }
};