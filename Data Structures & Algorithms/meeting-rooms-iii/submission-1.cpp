class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> awaiting;
        vector<bool> isUsed(n, false);
        unordered_map<int, int> count;
        vector<vector<int>> rooms(n);

        for(const auto& meeting : meetings){
            awaiting.push(meeting);
        }

        int time = awaiting.top()[0];
        while(!awaiting.empty()){
            for(int i = 0; i < rooms.size(); ++i){
                if(isUsed[i]){
                    if(rooms[i][1] <= time){
                        isUsed[i] = false;
                    }
                }
            }

            int i = 0;
            while(i < n){
                if(!isUsed[i]) break;
                i++;
            }

            if(i < n && awaiting.top()[0] <= time){
                count[i]++;
                vector<int> meeting = awaiting.top();
                awaiting.pop();
                rooms[i] = {time, time + meeting[1] - meeting[0]};
                isUsed[i] = true;
            }else if(i < n){
                time = awaiting.top()[0];
            }else{
                int minTime = INT_MAX;
                for(int i = 0; i < rooms.size(); ++i){
                    if(isUsed[i]){
                        minTime = min(minTime, rooms[i][1]);
                    }
                }
                time = minTime;
            }
        }

        int maxRoom, maxUsed = INT_MIN;
        for(const auto& p : count){
            if(p.second > maxUsed){
                maxRoom = p.first;
                maxUsed = p.second;
            }else if(p.second == maxUsed){
                maxRoom = min(maxRoom, p.first);
            }
        }

        return maxRoom;
    }
};