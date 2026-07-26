class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int curTime = 0;
        int processed = 0;
        bool hasTimeMoved = false;

        while(processed < tasks.size()){
            hasTimeMoved = false;
            for(int i = 0; i < tasks.size(); ++i){
                if(tasks[i][0] <= curTime){
                    minHeap.push({tasks[i][1], i});
                    tasks[i][0] = INT_MAX;
                }
            }

            if(!minHeap.empty()){
                pair<int,int> curTask = minHeap.top();
                minHeap.pop();

                res.push_back(curTask.second);
                processed++;
                curTime += curTask.first;
                hasTimeMoved = true;
            }
            
            if(!hasTimeMoved) curTime++;
        }

        return res;
    }
};