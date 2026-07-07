class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int> maxHeap;
        queue<pair<int,int>> taskQueue;
        vector<int> taskList(26, 0);

        for(const char& task : tasks){
            taskList[task - 'A']++;
        }

        for(int task : taskList){
            if(task > 0) maxHeap.push(task);
        }

        while(!maxHeap.empty() || !taskQueue.empty()){
            time++;

            if(maxHeap.empty()){
                time = taskQueue.front().second;
            }else{
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if(count) taskQueue.push({count, time + n});
            }

            if(time == taskQueue.front().second){
                maxHeap.push(taskQueue.front().first);
                taskQueue.pop();
            }
        }

        return time;
    }
};
