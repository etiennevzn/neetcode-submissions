class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long waitTime = 0;
        int curTime = customers[0][0];
        
        for(const vector<int>& customer : customers){
            int arrival = customer[0], wait = customer[1];
            if(curTime < arrival) curTime = arrival;
            waitTime += curTime + wait - arrival;
            curTime += wait;
        }

        return (double)waitTime / customers.size(); 
    }
};