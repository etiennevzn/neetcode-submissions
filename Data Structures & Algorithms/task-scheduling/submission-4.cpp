class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxf = 0;
        vector<int> count(26,0);
        for(const char& task : tasks){
            count[task-'A']++;
        }

        maxf = *max_element(count.begin(), count.end());
        
        int maxCount = 0;
        for(int c : count){
            if(c == maxf) maxCount++;
        }

        int time = (maxf - 1) * (n + 1) + maxCount;
        return max(time, (int)tasks.size());
    }
};
