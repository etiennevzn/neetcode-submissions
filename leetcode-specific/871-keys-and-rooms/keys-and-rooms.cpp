class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> roomQueue;
        vector<bool> visited(n, false);
        int count = 0;

        roomQueue.push(0);
        visited[0] = true;
        count++;

        while(!roomQueue.empty()){
            int cur = roomQueue.front();
            roomQueue.pop();

            for(int room : rooms[cur]){
                if(visited[room]) continue;
                roomQueue.push(room);
                visited[room] = true;
                count++;
            }
        }

        return count == n;
    }
};