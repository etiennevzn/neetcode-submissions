class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int> maxHeap;
        queue<pair<int,int>> taskQueue;
        unordered_map<char,int> taskMap;

        for(const char& task : tasks){
            taskMap[task]++;
        }

        for(const auto& [task, count] : taskMap){
            maxHeap.push(count);
        }

        while(!maxHeap.empty() || !taskQueue.empty()){
            time++;

            if(maxHeap.empty()){
                time = taskQueue.front().second;
            }else{
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if(count > 0) taskQueue.push({count, time + n});
            }

            if(!taskQueue.empty() && taskQueue.front().second == time){
                maxHeap.push(taskQueue.front().first);
                taskQueue.pop();
            }
        }

        return time;
    }
};
